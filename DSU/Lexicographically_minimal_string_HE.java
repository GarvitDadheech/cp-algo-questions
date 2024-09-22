import java.io.*;
import java.util.*;


public class Lexicographically_minimal_string_HE {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter wr = new PrintWriter(System.out);
         String A = br.readLine();
         String B = br.readLine();
         String C = br.readLine();

         String out_ = Solution(A, C, B);
         System.out.println(out_);

         wr.close();
         br.close();
    }
    static String Solution(String A, String C, String B){
        DSU dsu = new DSU(26);
        for(int i=0;i<A.length();i++) {
            int f = A.charAt(i) - 'a';
            int s = B.charAt(i) - 'a';
            dsu.unite(f,s);
        }
        String ans = "";
        for(int i=0;i<C.length();i++) {
            int root = dsu.find(C.charAt(i)-'a');
            ans += (char)(dsu.min[root]+'a');
        }    
        return ans;
    }
}
class DSU{
    int parent[];
    int min[];
    public DSU(int n) {
        parent = new int[n];
        min = new int[n];
        for(int i=0;i<n;i++) {
            parent[i] = i;
            min[i] = i;
        }
    }
    int find(int x) {
        if(x==parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void unite(int x,int y) {
        int xp = find(x);
        int yp = find(y);
        if(xp==yp) {
            return;
        }
        min[yp] = Math.min(min[xp],min[yp]);
        parent[xp] = yp;
    }
}