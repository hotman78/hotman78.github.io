struct SEG{
  lint n=1;
  vector<lint> node;
  SEG(lint size){
      while(n<size)n*=2;
      node.resize(2*n-1,0);
  }
  void add(lint x,lint val){
      x+=n-1;
      node[x]+=val;
      while(x>0){
          x=(x-1)/2;
          node[x]=node[2*x+1]+node[2*x+2];
      }
  }
  lint get(lint a,lint b,lint k=0,lint l=0,lint r=-1){
      if(r<0)r=n;
      if(r<=a||b<=l)return 0;
      if(a<=l&&r<=b)return node[k];
      return get(a,b,2*k+1,l,(l+r)/2)+get(a,b,2*k+2,(l+r)/2,r);
  }
};