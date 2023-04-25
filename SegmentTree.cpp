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
void update(int id,int l,int r,int re,char a,char b)
{
    if(l==r && l==re)
    {
        if(a=='a') tt[id].a--;
        else if(a=='b') tt[id].b--;
        else tt[id].c--;
        if(b=='a') tt[id].a++;
        else if(b=='b') tt[id].b++;
        else tt[id].c++;
        return;
    }
    if(l>re || r<re) return;
    int mid=(l+r)/2;
    update(2*id + 1,l,mid,re,a,b);
    update(2*id + 2,mid+1,r,re,a,b);
    tt[id].a=tt[2*id +1].a + tt[2*id +2].a;
    tt[id].b=tt[2*id +1].b + tt[2*id +2].b;
    tt[id].c=tt[2*id +1].c + tt[2*id +2].c;
    return;
}
