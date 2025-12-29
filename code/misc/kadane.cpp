ll arns = v[0], maxSum = 0;
fori(i,0,n)
{
  maxSum += v[i];
  arns = max(arns, maxSum);
  maxSum = max(0LL,maxSum);
}
