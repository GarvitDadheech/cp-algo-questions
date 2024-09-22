import java.util.ArrayList;

public class EulerTour {

    static void eulerTour(int node,int parent,ArrayList<Integer> tour,ArrayList<ArrayList<Integer>> adj) {
        tour.add(node);
        for(int nb : adj.get(node)) {
            if(nb!=parent) {
                eulerTour(nb,node,tour,adj);
            }
        }
        tour.add(node);
    }

    public static void main(String[] args) {
        int n = 5;

        // Adjacency list representing the tree
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        // Adding edges of the tree
        adj.get(0).add(1);
        adj.get(1).add(0);

        adj.get(0).add(2);
        adj.get(2).add(0);

        adj.get(1).add(3);
        adj.get(3).add(1);

        adj.get(1).add(4);
        adj.get(4).add(1);

        // Expected tree structure:
        //     0
        //    / \
        //   1   2
        //  / \
        // 3   4

        ArrayList<Integer> tour = new ArrayList<>();

        // Call the Euler Tour starting from node 0 and with parent as -1
        eulerTour(0, -1, tour, adj);

        // Print the Euler tour
        System.out.println("Euler Tour: " + tour);
    }
}
