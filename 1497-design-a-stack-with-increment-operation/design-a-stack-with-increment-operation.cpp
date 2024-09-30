class CustomStack {
public:
int vec[1001];
int i=0,lim;
    CustomStack(int maxSize) {
        lim=maxSize;
    }
    
    void push(int x) {
        if(i<lim){
            vec[i]=x;
            i++;
        }
    }
    
    int pop() {
        if(i==0)return -1;
        i--;
        return vec[i];
    }
    
    void increment(int k, int val) {
        for(int j=0;j<min(i,k);++j)vec[j]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */