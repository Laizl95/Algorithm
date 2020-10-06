### 前缀函数：给定一个长度为n的字符串，前缀函数被定义为长度为n的数组pi.
pi[i] 定义:
>1.如果子串s[0..i]有一对相等的真前缀与真后缀：s[0..k-1]和s[i-k+1...i],那么pi[i]就是这个相等的真前缀的长度，也就是pi[i]=k；

>2.如果不止有一对相等的，那么pi[i]就是其中最长的那一对的长度；

>3.如果没有相等的，那么pi[i]=0
### 前缀函数算法 复杂度O(n)：

```
vector<int> prefixFunction(string s) {
  vector<int> pi(n);
  pi[0]=0;
  for(int i=1;i<s.length();++i){
    int j=pi[i-1];
    while(j>0 && s[i]!=s[j]) j=pi[j-1];
    if(s[i]==s[j]) pi[i]=j+1;
    else pi[i]=j;
  }
  return pi;
}
```

### 前缀函数的典型应用:kmp算法
给定一个文本t和一个字符串s,找出s在t中所有的出现。正如在前缀函数的计算的那样，如果我们知道前缀函数的值永远不超过一特定值(<=n)，那么我们不需要存储整个字符串以及整个前缀函数，而只需要二者开头的一部分。在我们这种情况下这意味着只需要存储字符串s+#及相应的前缀函数值即可。我们可以一次读入字符串t的一个字符并计算当前位置的前缀函数值。
```
// 1.求出字符串s的前缀函数
vector<int> prefixFunction(string s) {
    vector<int> pi(n);
    pi[0]=0;
    for(int i=1;i<s.length();++i){
        int j=pi[i-1];
        while(j>0 && s[i]!=s[j]) j=pi[j-1];
        if(s[i]==s[j]) ++j;
        pi[i]=j;
    }
  return pi;
}
// 2.KMP求字符串s在文本t中首次出现的位置
int kmpIdenx(string s,string t){
    int lens=s.length(),lent=t.length(),i=0,j=0;
    while(i<lent && j<lens){
        if(s[j]==t[i]) ++i,++j;
        else {
            if(j==0) ++i;
            else j=pi[j-1];
        }
    }
    if(j==lens) return i-lens;
    return -1;
}
// 3.KMP求字符串s在文本t中出现次数
int kmpCnt(string s,string t){
    int lens=s.length(),lent=t.length(),j=0,cnt=0;
    for(int i=0;i<lent;++i){
        while(j>0 && s[j]!=t[i]) j=pi[j-1];
        if(s[j]==t[i]) ++j;
        if(j==lens){
            ++cnt;
            j=pi[j-1];
        }
    }
    return cnt;
}

```