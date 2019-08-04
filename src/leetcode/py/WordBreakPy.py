class Solution:

    def wordBreak(self, s, wordDict):
        personal = {}
        for each in wordDict:
            personal[each] = 1
        personal_char_wise = {}
        for each in personal.keys():
            first_char = each[0]
            prev = personal_char_wise.get(first_char, [])
            prev.append(each)
            personal_char_wise[first_char] = prev

        return self.wordBreakUtil(s, 0, len(s) - 1, wordDict, personal, personal_char_wise)

    def wordBreakUtil(self, s, start_index, end_index, wordDict, personal, personal_char_wise):
        if end_index < start_index:
            return False
        ans = True
        if s[start_index] in personal_char_wise.keys():
            values = personal_char_wise[s[start_index]]
            for val in values:
                ans_temp = self.wordBreakUtil(s, start_index + len(val)-1, end_index, wordDict, personal, personal_char_wise)
                ans = ans and ans_temp
                if not ans:
                    personal[val] = 0
        else:
            ans=False
        return ans


if __name__ == '__main__':
    s = Solution()
    print(s.wordBreak(s="sanddog", wordDict=["cats", "dog", "sand", "and", "cat"]))
