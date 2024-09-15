pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	int low = 0, high = n-1;
	int floor = -1, ceil = -1;

	// binary search
	while(low <= high){
		int mid = low + (high-low)/2;
		if(a[mid] == x){
			floor = a[mid];
			ceil = a[mid];
			return {floor, ceil};  
		}else if(a[mid] < x){
			floor = a[mid];
			low = mid+1;
		}else{
			ceil = a[mid];
			high = mid -1;
		}
	}
	return {floor, ceil};
}