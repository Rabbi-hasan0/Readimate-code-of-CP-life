//first-> descending and second value-> ascending
bool cmp1(pair<int,int>&a, pair<int,int>&b){ 
    if(a.first != b.first){
        return a.first > b.first;
    }else{
        return a.second < b.second;
    }
}
//first-> ascending and second value-> descending
bool cmp2(pair<int, int>& a, pair<int, int>& b) {
    if (a.first != b.first) {
        return a.first < b.first; 
    } else {
        return a.second > b.second; 
    }
}
