class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        counter=Counter(nums)
        permutations =[]
        def findAllpermutation(res):
            if(len(res)==len(nums)):
                permutations .append(res)
                return
            
            for key in counter:
                if counter[key]:
                    counter[key]-=1
                    findAllpermutation(res+[key])
                    counter[key]+=1
        findAllpermutation([])
        return permutations 
        