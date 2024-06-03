#!/usr/bin/python3
"""A recursive function that queries the Reddit API,
parses the title of all hot articles,
and prints a sorted count of given keywords
"""

import requests


def count_words(subreddit, word_list, after=None, counter_dictionary=None):
    """
    Args:
        subreddit (str): subreddit to query
        word_list (list of str): the list of keywords to count
        after (str): the after parameter for pagination
        counter_dictionary (dict): dictionary to keep track of counts

    Returns: nothing
    """

    # Initialize counter dictionary if it's the first call
    if counter_dictionary is None:
        counter_dictionary = {}

    # Basic validation
    if not subreddit or not word_list:
        return

    # Fetching data
    url_access = f'https://www.reddit.com/r/{subreddit}/hot.json'
    params = {'after': after} if after else {}
    headers = {'User-agent': 'Mozilla/5.0'}

    response = requests.get(url_access, params=params,
                            headers=headers, allow_redirects=False)

    if response.status_code != 200:
        return

    data = response.json().get("data", {})

    # Word list to lowercase and check if keyword is in title
    for keyword in word_list:
        keyword = keyword.lower()

        for thread in data.get('children', []):
            title = thread.get("data", {}).get("title", "").lower()
            occurrence = title.split().count(keyword)
            if occurrence > 0:
                if keyword not in counter_dictionary:
                    counter_dictionary[keyword] = occurrence
                else:
                    counter_dictionary[keyword] += occurrence

    # Go to next data batch
    after = data.get('after')
    if after:
        return count_words(subreddit, word_list, after,
                           counter_dictionary=counter_dictionary)
    else:
        if len(counter_dictionary) == 0:
            return

        for key, value in sorted(counter_dictionary.items(), key=lambda kv: (-kv[1], kv[0])):
            print('{}: {}'.format(key, value))
