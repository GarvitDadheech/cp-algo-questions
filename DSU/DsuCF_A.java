package DSU;
import java.util.Scanner;

public class DsuCF_A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        DS dsu = new DS(n+1);
        sc.nextLine();
        while(m>0) {
            String[] input = sc.nextLine().split(" ");
            String op = input[0];
            int a = Integer.parseInt(input[1]);
            int b = Integer.parseInt(input[2]);
            if(op.equals("union")) {
                dsu.union(a, b);
            }
            else{
                if(dsu.get(a, b)) {
                    System.out.println("YES");
                }
                else{
                    System.out.println("NO");
                }
            }
            m--;
        }
        sc.close();
    }
}
class DS{
    int parent[];
    int rank[];
    int N;
    public DS(int n) {
        this.N = n;
        parent = new int[n];
        rank = new int[n];
        for(int i=0;i<n;i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int findParent(int a) {
        if(parent[a]==a) {
            return a;
        }
        return parent[a] = findParent(parent[a]);
    }
    boolean get(int a,int b) {
        return findParent(a) == findParent(b);
    }
    void union(int a,int b) {
        int ap = findParent(a);
        int bp = findParent(b);
        if(ap!=bp) {
            int rankA = rank[ap];
            int rankB = rank[bp];
            if(rankA<rankB) {
                parent[ap] = bp;
            }
            else if(rankB<rankA) {
                parent[bp] = ap;
            }
            else{
                parent[bp] = ap;
                rank[ap]++;
            }
        }
    }
}
