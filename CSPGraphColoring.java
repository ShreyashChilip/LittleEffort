import java.util.*;

public class CSPGraphColoring {
    private int numVertices;
    private Map<Integer, List<Integer>> adjacencyList;
    private int[] colors; 

    public CSPGraphColoring(int numVertices) {
        this.numVertices = numVertices;
        adjacencyList = new HashMap<>();
        colors = new int[numVertices];

        for (int i = 0; i < numVertices; i++) {
            adjacencyList.put(i, new ArrayList<>());
        }
    }
    public void addEdge(int u, int v) {
        adjacencyList.get(u).add(v);
        adjacencyList.get(v).add(u);
    }

    private boolean isSafe(int v, int c) {
        for (int neighbor : adjacencyList.get(v)) {
            if (colors[neighbor] == c) {
                return false;
            }
        }
        return true;
    }
    public boolean solve(int vertex, int numColors) {
        if (vertex == numVertices) {
            return true;
        }

        for (int c = 1; c <= numColors; c++) {
            if (isSafe(vertex, c)) {
                colors[vertex] = c;
                if (solve(vertex + 1, numColors)) {
                    return true;
                }
                colors[vertex] = 0;
            }
        }

        return false; 
    }

    public void printSolution() {
        for (int i = 0; i < numVertices; i++) {
            System.out.println("Vertex " + i + " ---> Color " + colors[i]);
        }
    }

    public static void main(String[] args) {
        int numVertices = 5;
        CSPGraphColoring graph = new CSPGraphColoring(numVertices);

        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 2);
        graph.addEdge(1, 3);
        graph.addEdge(2, 4);

        int numColors = 3;
        if (graph.solve(0, numColors)) {
            graph.printSolution();
        } else {
            System.out.println("No solution exists with " + numColors + " colors.");
        }
    }
}
