int count_num(i64 n, int div)
{
    int count;
    
    count = 0;
    while (n > 0 && n % div == 0)
    {
        count++;  
        n /= div;
    }
    return (count);
}
 
int main() {
    i64 n;
    int k;
    scanf("%lld %d", &n, &k);
    
    if (k == 0)
    {
        printf("%lld", n);
        return (0);
    }
    
    int a = count_num(n, 5);
    int b = count_num(n, 2);
    //cout << a << " " << b << endl;
    
    for (int i = a; i < k; i++)
        n *= 5;
    for (int i = b; i < k; i++)
        n *= 2;
    
    printf("%lld\n", n);
    
    return 0;
}