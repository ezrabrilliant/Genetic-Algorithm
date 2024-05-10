#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include <ctime>
#include <limits>
#include <cstdlib>
#include <random>

using namespace std;

namespace fs = std::filesystem;

struct node {
    int a[1];

    node(int dst) {
        this->a[0] = dst;
    }
};

struct Graph {
    int V;
    vector<vector<node>> g;

    Graph(int V) {
        this->V = V;
        g = vector<vector<node>>(V, vector<node>(V, node(-1)));
    }

    void addEdge(int src, int dst) {
        g[src][dst] = node(dst);
        g[dst][src] = node(src);
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Adjacency list of vertex " << i << ": ";
            for (int j = 0; j < V; j++) {
                if (g[i][j].a[0] != -1) {
                    cout << "-> " << g[i][j].a[0];
                }
            }
            cout << endl;
        }
    }
};

int fitnessFunc(vector<int> chrom, Graph graph, int V) {
    int value = 1;
    Graph newGraf = graph;

    for (int i = 0; i<graph.g.size(); i++){
        for (int j = 0; j < graph.g.size(); ++j) {
            if (newGraf.g[i][j].a[0] != -1) {
                if (chrom[i] != chrom[newGraf.g[i][j].a[0]]){
                    value += 1;
                    newGraf.g[i][j].a[0] = -1;
                    newGraf.g[j][i].a[0] = -1;
                }
            }
        }
    }

    int colorValue = V;
    vector<int> checkedColor;
    for (int i : chrom) {
        bool condition = true;
        if (checkedColor.empty()){
            checkedColor.push_back(i);
            colorValue = colorValue-1;
        }else{
            for (int j : checkedColor) {
                if (i == j){
                    condition = false;
                }
            }
            if (condition){
                checkedColor.push_back(i);
                colorValue = colorValue-1;
            }
        }
    }

    value = value + colorValue;
    return value;
}

void Output(string Namafile, vector<int> hasil, int JumlahWarna) {
    fs::path currentDir = fs::current_path();
    fs::path outputPath = currentDir.parent_path() / ("out_" + Namafile);
    ofstream outputFile(outputPath);

    if (!outputFile.is_open()) {
        cerr << "Error creating output file: " << outputPath << endl;
        return;
    }

    outputFile << JumlahWarna << endl;
    for (int i : hasil) {
        outputFile << i;
    }
    outputFile << endl;
    outputFile.close();
}

Graph Input(const string& Namafile) {
    fs::path currentDir = fs::current_path();
    fs::path inputPath = currentDir.parent_path() / Namafile;
    ifstream inputFile(inputPath);

    if (!inputFile.is_open()) {
        cerr << "Error opening file for reading: " << inputPath << endl;
        return Graph(0);
    }

    int V, E;
    inputFile >> V >> E;

    Graph graph(V);

    for (int i = 0; i < E; i++) {
        int v0, v1;
        inputFile >> v0 >> v1;
        graph.addEdge(v0, v1);
    }

    inputFile.close();
    return graph;
}

vector<int> GeneticAlgorithm(Graph graph) {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    srand(getpid());

    int V = graph.V;
    vector<vector<int>> currPopulation;
    vector<vector<int>> newPopulation;
    int bestValue = 0;
    vector<int> currBest;

    //FILLING POPULATION
    for (int i = 0; i < 100; i++) {
        vector<int> temp;
        for (int j = 0; j < V; j++) {
            temp.push_back(rng() % V);
        }
        currPopulation.push_back(temp);
    }
    vector<int> roulette;
    for (int z = 0; z < 10; ++z) {
        newPopulation.clear();
        //FILLING ROULETTE
        roulette.clear();
        for(int i = 0; i<100; i++){
            int value = fitnessFunc(currPopulation[i], graph, V);
            if (value > bestValue){
                bestValue = value;
                currBest = currPopulation[i];
            }
            for (int j = 0; j < value; ++j) {
                roulette.push_back(i);
            }
        }
        for (int y = 0; y < currPopulation.size(); ++y) {
            //SELECTION
            vector<int> parent1;
            vector<int> parent2;

            //Roulette
            int indexParent1 = roulette[rng() % roulette.size()];
            int indexParent2 = roulette[rng() % roulette.size()];

            for (int i = 0; i < V; ++i) {
                parent1.push_back(currPopulation[indexParent1][i]);
                parent2.push_back(currPopulation[indexParent2][i]);
            }

            //CROSSING
            vector<int> child1;
            vector<int> child2;

            int crossPoint = parent1.size()/2;

            for (int i = 0; i < parent1.size(); ++i) {
                if (i < crossPoint){
                    child1.push_back(parent1[i]);
                    child2.push_back(parent2[i]);
                }else{
                    child1.push_back(parent2[i]);
                    child2.push_back(parent1[i]);
                }
            }

            //MUTATION
            int randNum = rng() % 100;
            int randIndex1 = rng() % V;
            int randIndex2 = rng() % V;
            if (randNum <= 20){
                child1[randIndex1] = rng() % V;
                child2[randIndex2] = rng() % V;
            }

            newPopulation.push_back(child1);
            newPopulation.push_back(child2);
        }
        currPopulation = newPopulation;
    }

    return currBest;
}

int CountJumlahWarna(vector<int> hasil) {
    int jumlahWarna = 0;
    vector<int> checkedColor;
    for (int i = 0; i < hasil.size(); ++i) {
        bool condition = true;
        if (checkedColor.empty()){
            checkedColor.push_back(hasil[i]);
            jumlahWarna += 1;
        }else{
            for (int j = 0; j < checkedColor.size(); ++j) {
                if (hasil[i] == checkedColor[j]){
                    condition = false;
                }
            }
            if (condition){
                checkedColor.push_back(hasil[i]);
                jumlahWarna += 1;
            }
        }
    }
    return jumlahWarna;
}

int main() {
    string Namafile = "gc_4_1.txt";

    Graph graph = Input(Namafile);

    graph.printGraph();

    vector<int> hasil = GeneticAlgorithm(graph);

    int jumlahWarna = CountJumlahWarna(hasil);

    Output(Namafile, hasil, jumlahWarna);

    return 0;
}
