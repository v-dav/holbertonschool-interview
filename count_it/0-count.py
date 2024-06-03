#!/usr/bin/python3
"""A recursive function that queries the Reddit API,
parses the title of all hot articles,
and prints a sorted count of given keywords
"""

import os
import requests


# Initialize counter dictionary
counter_dictionary = {}


def count_words(subreddit, word_list, after=None, print_results=True):
    """
    Args:
            subreddit (str): subreddit to query
            word_list (list of str): the list of keywords to count
            after (str): the after parameter for pagination
            print_results (bool): flag to print results after recursion

    Returns: nothing
    """

    # Basic validation
    if (subreddit is None or
        subreddit == "" or
        word_list is None or
            word_list == []):
        return

    # Fetching data
    url_access = f'https://reddit.com/r/{subreddit}/hot.json'
    params = {'after': after} if after else {}
    response = requests.get(url_access, params=params)

    if response.status_code != 200:
        return

    data = response.json()["data"]

    # Word list to lowercase and check if kw in title
    for keyword in word_list:
        keyword = keyword.lower()
        if keyword not in counter_dictionary:
            counter_dictionary[keyword] = 0

        for thread in data['children']:
            if keyword in thread['data']['title'].lower():
                counter_dictionary[keyword] += 1

    # Go to next data batch
    after = data.get('after')
    if after:
        count_words(subreddit, word_list, after, print_results=False)

    # Print formatted counter dictionary
    if print_results:
        for keyword in counter_dictionary:
            if counter_dictionary[keyword] != 0:
                print(f'{keyword}: {counter_dictionary[keyword]}')
