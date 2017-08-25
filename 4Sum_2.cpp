class Solution {
public:
    struct Sum{
      int sum;
      int a;
      int b;
      Sum(int _sum,int _a,int _b){
          sum = _sum;
          a = _a;
          b = _b;
      }
      bool operator < (const Sum & other) const{
          return sum < other.sum;
      }
    };
    
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<Sum> twoSum;
        for(int i = 0; i < num.size() ; i++){
            for(int j = i+1; j < num.size() ;j++){
                twoSum.push_back(Sum(num[i] + num[j],i,j));
            }
        }
        
        sort(twoSum.begin(),twoSum.end());
        
        vector<vector<int> > ans;
        
        int left = 0, right = twoSum.size()-1;
        
        while(left < right){
            // cout << left << " " << right << endl;
            // cout << twoSum[left].sum << endl;
            if(twoSum[left].sum + twoSum[right].sum == target){
                int x = left , y = right;
                for(;x < y && twoSum[x].sum == twoSum[left].sum; x++){
                    for(y = right;x < y && twoSum[y].sum == twoSum[right].sum; y--){
                        if(!(twoSum[x].a == twoSum[y].a ||
                           twoSum[x].a == twoSum[y].b ||
                           twoSum[x].b == twoSum[y].a ||
                           twoSum[x].b == twoSum[y].b)){
                            vector<int> element;
                            element.push_back(num[twoSum[x].a]);
                            element.push_back(num[twoSum[x].b]);
                            element.push_back(num[twoSum[y].a]);
                            element.push_back(num[twoSum[y].b]);
                            sort(element.begin(),element.end());
                            ans.push_back(element);
                        }
                    }
                }
                left = x;
                right = y;
                
                
                // if(!(twoSum[left].a == twoSum[right].a ||
                //    twoSum[left].a == twoSum[right].b ||
                //    twoSum[left].b == twoSum[right].a ||
                //    twoSum[left].b == twoSum[right].b)){
                //     vector<int> element;
                //     element.push_back(num[twoSum[left].a]);
                //     element.push_back(num[twoSum[left].b]);
                //     element.push_back(num[twoSum[right].a]);
                //     element.push_back(num[twoSum[right].b]);
                //     sort(element.begin(),element.end());
                //     ans.push_back(element);
                // }
                //  left++;
            }else{
                if(twoSum[left].sum + twoSum[right].sum < target){
                    left++;
                }else{
                    right--;
                }
            }
        }
        
        sort(ans.begin(),ans.end());
		ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
    
		// vector<vector<int> > ret;
		// sort(num.begin(),num.end());
		// size_t len=num.size();
		// if(len < 4) return ret;
		// map<int,pair<int,int> > dict;
		// //缓存两个数的和
		// for(size_t i=0;i<len-1;i++)
		// {
		// 	for(size_t j=i+1;j<len;j++)
		// 	{
		// 		dict[num[i]+num[j]]=make_pair(i,j);
		// 	}
		// }
		// //遍历dict,类似于two sum
		// map<int,pair<int,int> >::const_iterator  map_it=dict.begin();
		// while(map_it != dict.end())
		// {
		// 	vector<pair<int,int> > tmp=twoSum(num,target-map_it->first);
		// 	for(vector<pair<int,int> >::iterator iter=tmp.begin();
		// 		iter!=tmp.end();iter++)
		// 	{
		// 		if(map_it->second.first!=iter->first && map_it->second.first!=iter->second
		// 			&& map_it->second.second!=iter->first&& map_it->second.second!=iter->second)
		// 		{
		// 			vector<int> unit;
		// 			unit.push_back(num[map_it->second.first]);
		// 			unit.push_back(num[map_it->second.second]);
		// 			unit.push_back(num[iter->first]);
		// 			unit.push_back(num[iter->second]);
		// 			sort(unit.begin(),unit.end());
		// 			ret.push_back(unit);
		// 		}
		// 	}
		// 	map_it++;
		// }
		// sort(ret.begin(),ret.end());
		// ret.erase(unique(ret.begin(),ret.end()),ret.end());
		// return ret;
    // }
    
	// vector<pair<int,int> > twoSum(const vector<int> &num,int sum)
	// {
	// 	vector<pair<int,int> > ret;
	// 	size_t aIndex=0,bIndex=num.size()-1;
	// 	while(aIndex < bIndex)
	// 	{
	// 		int tmp=num[aIndex]+num[bIndex];
	// 		if(tmp==sum)
	// 		{
	// 			pair<int,int> tmp;
	// 			tmp.first=aIndex;
	// 			tmp.second=bIndex;
	// 			ret.push_back(make_pair(aIndex,bIndex));
	// 			aIndex++;
	// 			/*while(aIndex < num.size()-1 && num[aIndex]==num[aIndex-1])
	// 			{
	// 				aIndex++;
	// 			}*/
	// 		}
	// 		else if(tmp > sum)
	// 		{
	// 			bIndex--;
	// 		}
	// 		else
	// 		{
	// 			aIndex++;
	// 		}
	// 	}
	// 	return ret;
	// }
};
