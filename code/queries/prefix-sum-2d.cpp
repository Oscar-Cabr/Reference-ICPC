for(int i = 1; i <= n; i++)
  for(int j = 1; j <= n; j++)
  {
    prefix[i][j] = prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1];
    prefix[i][j] += forest[i-1][j-1] == '*' ? 1 : 0;
  }
for(int i = 0; i < q; i++)
{
  pair<int,int> p1, p2;
  cin >> p1.fi >> p1.se >> p2.fi >> p2.se;
  int arns = prefix[p2.fi][p2.se];
  arns -= prefix[p2.fi][p1.se-1] + prefix[p1.fi-1][p2.se];
  arns += prefix[p1.fi-1][p1.se-1];
  cout << arns << endl;
}
