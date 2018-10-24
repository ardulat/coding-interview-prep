// https://www.interviewbit.com/problems/points-on-the-straight-line/

// Taken from web
struct pairhash {
public:
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &x) const
  {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};

int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    unordered_map<pair<int,int>,int,pairhash> ht;
    int currentMax, overlapping, vertical;
    int globalMax = 0;
    
    for (int i = 0; i < A.size(); i++) {
        currentMax = 0, overlapping = 0, vertical = 0;
        for (int j = i+1; j < A.size(); j++) {
            if (A[i] == A[j] && B[i] == B[j]) // overlapping
                overlapping++;
            else if (A[i] == A[j]) // vertical
                vertical++;
            else {
                int adif = A[j]-A[i];
                int bdif = B[j]-B[i];
                int g = __gcd(adif, bdif);
                adif /= g;
                bdif /= g;
                pair<int,int> p = make_pair(adif, bdif);
                if (ht.find(p) == ht.end())
                    ht[p] = 0;
                ht[p]++;
                currentMax = max(currentMax, ht[make_pair(adif, bdif)]);
            }
        }
        currentMax = max(currentMax, vertical);
        globalMax = max(globalMax, currentMax+overlapping+1);
        ht.clear();
    }
    return globalMax;
}
