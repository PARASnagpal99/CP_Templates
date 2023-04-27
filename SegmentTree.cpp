// Segment Tree Template 
int tt[800008];
void build(int id,int l,int r,int *a)
{
    if(l==r)
    {
        tt[id]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*id + 1,l,mid,a);
    build(2*id + 2,mid+1,r,a);
    tt[id]=max(tt[2*id +1],tt[2*id +2]);
    return;
}
int getAns(int l,int r,int qs,int qe,int id)
{
    if(qs>qe)
    {
       return INT_MIN;
    }
    if(l==qs && r==qe) return tt[id];
    int mid=(l+r)/2;
    int x=getAns(l,mid,qs,min(mid,qe),2*id +1);
    int y=getAns(mid+1,r,max(mid+1,qs),qe,2*id+2);
    return max(x,y);
}
void update(int id,int l , int r , int pos , int newVal)
{
    if(l == r){
        tt[id] = newVal ;
        return ;
    }    
    int mid = (l + r)/2 ;
    if(pos <= mid){
        update(2*id + 1 , l , mid , pos , newVal);
    }else{
        update(2*id + 2 , mid + 1 , r , pos , newVal);
    }
    
    tt[id] = min(tt[2*id + 1] , tt[2*id + 2]);    
    return;    
}
