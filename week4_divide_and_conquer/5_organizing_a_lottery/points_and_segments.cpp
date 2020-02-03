#include <iostream>
#include <vector>

using std::vector;

struct Seg{
  /* data */
  int x, y;
};

bool orderX (Seg i, Seg j){
  return (i.x < j.x);
}

bool orderY (Seg i, Seg j){
  return (i.y < j.y);
}

int searchX(vector<Seg> segments, int left, int right, int pnt){
  int pos = - 1;
  while(left <= right){
    if(left == right){
      Seg p = segments[left];
      if(p.x <= pnt){
        pos = left;
      }
      break;
    }
    int mid = left + (right - left) / 2;
    Seg p = segments[mid];
    if(p.x <= pnt){
      pos = mid;
      left = mid + 1;
    }else if(p.x > pnt){
      right = mid;
    }
  }
  return pos;
}

int searchY(vector<Seg> segments, int left, int right, int pnt){
  if(segments.empty()){
    return -1;
  }
  if(left == right){
    return segments[left].y > pnt ? left : -1;
  }
  int mid = left + (right - left) / 2;
  Seg p = segments[mid];
  if(p.y >= pnt){
    return searchY(segments, left, mid, pnt);
  }else{
    return searchY(segments, mid + 1, right, pnt);
  }
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  //write your code here
  vector<Seg> segments(starts.size());
  for(size_t i = 0; i < segments.size(); ++i){
    segments[i].x = starts[i];
    segments[i].y = ends[i];
  }
  sort(segments.begin(), segments.end(), orderX);
  for(int i = 0; i < points.size(); i++){
    int pos = searchX(segments, 0, segments.size() - 1, points[i]);
    if(pos != -1){
      vector<Seg> H(pos+1);
      for(size_t i = 0; i < pos + 1; ++i){
        H[i].x = segments[i].x;
        H[i].y = segments[i].y;
      }
      sort(segments.begin(), segments.end(), orderY);
      pos = searchY(H, 0, H.size() - 1, points[i]);
      int k = pos != -1 ? H.size() - pos : 0;
      cnt[i] = k;
    }else{
      cnt[i] = 0;
    }
  }
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
