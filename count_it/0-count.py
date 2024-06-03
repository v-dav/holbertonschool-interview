#!/usr/bin/python3
"""A recursive function that queries the Reddit API,
parses the title of all hot articles,
and prints a sorted count of given keywords
"""

import requests


def count_words(subreddit, word_list, after='', count={}):
    """
    Args:
        subreddit (str): subreddit to query
        word_list (list of str): the list of keywords to count
        after (str): the after parameter for pagination
        count (dict): dictionary to keep track of counts

    Returns: nothing
    """

    # Fetching data
    response = requests.get("https://www.reddit.com/r/{}/hot.json".format(subreddit),
                            headers={'User-agent': 'Mozilla/5.0'},
                            params={'after': after},
                            allow_redirects=False)

    if response.status_code != 200:
        return

    data = response.json().get('data')
    
    # Counting and formatting count dictionary
    for thread in data.get('children'):
        title = thread.get('data').get('title').lower()

        for keyword in word_list:
            keyword = keyword.lower()
            occurence = title.split().count(keyword)

            if occurence > 0:
                if keyword not in count:
                    count[keyword] = occurence
                else:
                    count[keyword] += occurence

    if data.get('after') is None:
        if not len(count) > 0:
            return

        for k, v in sorted(count.items(),
                           key=lambda kv: (-kv[1], kv[0])):
            print('{}: {}'.format(k.lower(), v))
    else:
        # Get next data batch
        return count_words(subreddit, word_list, data.get('after'), count)
