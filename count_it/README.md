# Reddit Keyword Counter

This project contains a recursive function that queries the Reddit API to parse and count the occurrences of specified keywords in the titles of hot articles from a given subreddit.

![Python](https://img.shields.io/badge/Python-blue?style=for-the-badge&logo=python&logoColor=white)

## 🧐 Project Overview

The `count_words` function queries the Reddit API, retrieves the titles of hot articles from a specified subreddit, and counts the occurrences of provided keywords. The results are printed in descending order based on the count of occurrences, with ties broken alphabetically. The function handles case-insensitive keywords and merges counts for duplicate keywords in the list.

## 🎓 Constraints

- The function must be called with a subreddit and a list of keywords.
- Results are printed in descending order of counts, with ties broken alphabetically (ascending).
- Only exact matches of keywords are counted (e.g., "java" counts as "java" but not "java.").
- Words must be printed in lowercase.
- If no posts match or the subreddit is invalid, the function prints nothing.
- The function must handle cases where invalid subreddits return a redirect to search results, ensuring that redirects are not followed.

## 🧑🏼‍💻 Usage Example

Here is an example of how to use the `count_words` function:

```python
bob@dylan $ cat 0-main.py 
#!/usr/bin/python3
"""
0-main
"""
import sys

if __name__ == '__main__':
    count_words = __import__('0-count').count_words
    if len(sys.argv) < 3:
        print("Usage: {} <subreddit> <list of keywords>".format(sys.argv[0]))
        print("Ex: {} programming 'python java javascript'".format(sys.argv[0]))
    else:
        result = count_words(sys.argv[1], [x for x in sys.argv[2].split()])
bob@dylan $             
bob@dylan $ python3 0-main.py programming 'react python java javascript scala no_results_for_this_one'
java: 27
javascript: 20
python: 17
react: 17
scala: 4
bob@dylan $ python3 0-main.py programming 'JavA java'
java: 54
bob@dylan $ python3 0-main.py not_a_valid_subreddit 'python java javascript scala no_results_for_this_one'
bob@dylan $ python3 0-main.py not_a_valid_subreddit 'python java'
bob@dylan $
```

## 🙇 Author

[Vladimir Davidov](https://github.com/v-dav) - Holberton School

