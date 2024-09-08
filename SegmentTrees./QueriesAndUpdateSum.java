import java.util.*;
class SegmentTree {
    int tree[];
    int N; //size of array
    int identity;
    public SegmentTree(int n,int identity) {
        N=n;
        this.identity = identity;
        tree = new int[4*n];
        for(int i=0;i<tree.length;i++){
            tree[i] = identity;
        }
    }

    int merge(int a,int b){
        return a+b;
    }

    void updateTree(int Qindx,int val) {
        helpUpdate(0,0,N-1,val,Qindx);
    }   

    void helpUpdate(int tIndx,int tL, int tR,int val,int Qindx) {
        if(tL==tR){
            tree[tIndx]  = val;
            return;
        }
        int tM = (tL+tR)/2;
        if(tL<=Qindx && Qindx<=tM) {
            helpUpdate(2*tIndx+1, tL, tM, val, Qindx);
        }
        else{
            helpUpdate(2*tIndx+2, tM+1, tR, val, Qindx);
        }
        tree[tIndx] = merge(tree[2*tIndx+1],tree[2*tIndx+2]);
    }

    int query(int l,int r) {
        return helpQuery(0, 0, N-1, l, r);
    }

    int helpQuery(int tIndx,int tL,int tR,int l,int r) {
        if(l>tR && r>tL) {
            return identity;
        }
        if(l<= tL && r<=tR){
            return tree[tIndx];
        }
        int tM = (tL+tR)/2;
        return merge(helpQuery(2*tIndx+1, tL, tM, l, r),helpQuery(2*tIndx+2, tM+1, tR, l, r));
    }

}


public class QueriesAndUpdateSum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int Q = sc.nextInt();
        int A[] = new int[N];
        SegmentTree st = new SegmentTree(N+1, 0);
        for(int i=1;i<=N;i++) {
            A[i] = sc.nextInt();
            st.updateTree(i,A[i]);
        }
        while(Q>0) {
            int t = sc.nextInt();
            if(t==1) {
                int indx = sc.nextInt();
                int val = sc.nextInt();
                st.updateTree(indx, val);

            }
            else {
                int l = sc.nextInt();
                int r = sc.nextInt();
                System.out.println(st.query(l, r));
            }
        }
        Q--;
    }
    
}
