package DSU;
import java.util.Scanner;

public class Dsu_CF_B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        DS dsu = new DS(n+1);
        
        for (int i = 0; i < m; i++) {
            String operation = sc.next();
            if (operation.equals("union")) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                dsu.union(u, v);
            } else {
                int v = sc.nextInt();
                System.out.println(dsu.getMin(v) + " " + dsu.getMax(v) + " " + dsu.getSize(v));
            }
        }
        sc.close();
    }
}

class DS {
    int[] parent, rank, min, max, size;

    public DS(int n) {
        parent = new int[n];
        rank = new int[n];
        min = new int[n];
        max = new int[n];
        size = new int[n];
        
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            min[i] = i;
            max[i] = i;
            size[i] = 1;
            rank[i] = 0;
        }
    }

    public int findParent(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }

    public void union(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);
        
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
                update(rootU, rootV);
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
                update(rootV, rootU);
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
                update(rootU, rootV);
            }
        }
    }

    void update(int root, int otherRoot) {
        min[root] = Math.min(min[root], min[otherRoot]);
        max[root] = Math.max(max[root], max[otherRoot]);
        size[root] += size[otherRoot];
    }

    public int getMin(int x) {
        return min[findParent(x)];
    }

    public int getMax(int x) {
        return max[findParent(x)];
    }

    public int getSize(int x) {
        return size[findParent(x)];
    }
}
