//¶þ·ÖËÑË÷

template<class T>
int binarysearch(T a[],T x,int n)
{
    int first=0;
    int last=n-1;
    while(first<=last)
    {
        int middle=(first+last)/2;
        if(a[middle]==x)
            return middle;
        if(a[middle]>x)
            last=middle-1;
        else
            first=middle+1;
    }
    return -1;
}


