#include <iostream>
#include <vector>

using namespace std;

struct Rectangle{
		int width;
		int height;
		bool toBeDeleted = false;
};

bool isHigher(Rectangle& firstRect, Rectangle& secondRect){
	if(firstRect.height < secondRect.height){
		return false;
	} else
	if(firstRect.height == secondRect.height){
		if(firstRect.width > secondRect.width){
			secondRect.toBeDeleted = true;
		}
		else firstRect.toBeDeleted = true;
		
		return false;
	}
	return true;
};

int main(){

	int n; cin >> n;
	vector<Rectangle> rects;
	
	
	for(int i = 0; i < n; i++){
		Rectangle rectangle; cin >> rectangle.width >> rectangle.height;
		rectangle.width /= 2; rectangle.height /= 2;
		rects.push_back(rectangle);	
	}
	
	sort(rects.begin(), rects.end(), isHigher);
	
	cout <<	rects.at(0).width <<	" " << rects.at(0).height << endl;
	cout <<	rects.at(0).toBeDeleted;
	
}