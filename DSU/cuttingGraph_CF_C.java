package DSU;

import java.util.*;

public class cuttingGraph_CF_C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();

        List<int[]> edges = new ArrayList<>();
        List<String> queries = new ArrayList<>();
        Map<String, Boolean> edgeCutMap = new HashMap<>();

        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            edges.add(new int[]{u, v});
        }
        
        sc.nextLine();
        
        for (int i = 0; i < k; i++) {
            String line = sc.nextLine();
            queries.add(line);
            String[] parts = line.split(" ");
            if (parts[0].equals("cut")) {
                int u = Integer.parseInt(parts[1]);
                int v = Integer.parseInt(parts[2]);
                edgeCutMap.put(u + "-" + v, true);
                edgeCutMap.put(v + "-" + u, true);
            }
        }

        DS dsu = new DS(n + 1);
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if (!edgeCutMap.containsKey(u + "-" + v)) {
                dsu.union(u, v);
            }
        }

        List<String> result = new ArrayList<>();
        for (int i = queries.size() - 1; i >= 0; i--) {
            String[] parts = queries.get(i).split(" ");
            String op = parts[0];
            int u = Integer.parseInt(parts[1]);
            int v = Integer.parseInt(parts[2]);

            if (op.equals("ask")) {
                if (dsu.get(u, v)) {
                    result.add("YES");
                } else {
                    result.add("NO");
                }
            } else if (op.equals("cut")) {
                dsu.union(u, v);
            }
        }

        Collections.reverse(result);
        for (String res : result) {
            System.out.println(res);
        }

        sc.close();
    }
}

class DS {
    int parent[];
    int rank[];

    public DS(int n) {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int findParent(int a) {
        if (parent[a] == a) {
            return a;
        }
        return parent[a] = findParent(parent[a]);
    }

    boolean get(int a, int b) {
        return findParent(a) == findParent(b);
    }

    void union(int a, int b) {
        int ap = findParent(a);
        int bp = findParent(b);
        if (ap != bp) {
            if (rank[ap] < rank[bp]) {
                parent[ap] = bp;
            } else if (rank[bp] < rank[ap]) {
                parent[bp] = ap;
            } else {
                parent[bp] = ap;
                rank[ap]++;
            }
        }
    }
}

