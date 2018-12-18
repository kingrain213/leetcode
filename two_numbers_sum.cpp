/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/
//2018-12-15
//method1
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i+1; j < nums.size(); ++j)
            {
                if (target == nums[i] + nums[j])
                {
                    result.push_back(i);
                    result.push_back(j);
                    break;    
                }
            }
            if (result.size() > 0)
                break;
        }
        
        return result;
    }
};

//method2 采用hash map寻址方法：
/*
两次for循环，第一次数据存储
for(int i = 0; i < nums.size(); ++i)
{
    //将数值放在key字段，索引放在val字段，进行存储
    key = nums[i]
    val = i
}
第二次查找
for(int i = 0; i < nums.size(); ++i)
{
    //遍历当前key，再看target-key是否也在键值对中
    //在的话，返回hash_map[key],hash_map[target-key]即可
}
*/

//method3 采用hash map寻址方法，一次循环即可：
/*
一次for循环，边存储数据，边查看是否在hash表中
初始化hashmap
for(int i = 0; i < nums.size(); ++i)
{
    //将数值放在key字段，索引放在val字段，进行存储
    val = nums[i]
    if (target - val in hashmap.keys())
        return i, hashmap[target -val]
    //不用担心缺失数据，比如target是8，数组是{1,2,3,7}
    //第一次操作1的时候，hashmap为空，找不到，但最后一次操作
    //7的时候，hashmap的key是有1的
}

*/
