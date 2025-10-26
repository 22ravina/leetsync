int min(int a,int b){
    if(a>b){
        return b;
    }
    return a;
}
int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
int maxArea(int* height, int heightSize) {
    int maxWater =0;
    int lp =0;
    int rp = heightSize-1;
    int ht;
    int width;
    while(lp<rp){
        width = rp-lp;
        ht = min(height[lp],height[rp]);
        int currW = width * ht;
        maxWater = max(currW,maxWater);
        if(height[lp]<height[rp]){
            lp++;
        }else{
            rp--;
        }
    }
    return maxWater;
    
}