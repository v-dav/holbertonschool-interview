#!/usr/bin/python3
"""A recursive function that queries the Reddit API,
parses the title of all hot articles,
and prints a sorted count of given keywords
"""

import requests

def count_words(subreddit, word_list, after=None, print_results=True, counter_dictionary=None):
    """
    Args:
        subreddit (str): subreddit to query
        word_list (list of str): the list of keywords to count
        after (str): the after parameter for pagination
        print_results (bool): flag to print results after recursion
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

    try:
        response = requests.get(url_access, params=params, headers=headers)
        response.raise_for_status()
    except requests.exceptions.RequestException as e:
        print(f"Error fetching data from Reddit: {e}")
        return

    data = response.json().get("data", {})

    # Word list to lowercase and check if keyword is in title
    for keyword in word_list:
        keyword = keyword.lower()
        if keyword not in counter_dictionary:
            counter_dictionary[keyword] = 0

        for thread in data.get('children', []):
            if keyword in thread['data']['title'].lower():
                counter_dictionary[keyword] += 1

    # Go to next data batch
    after = data.get('after')
    if after:
        count_words(subreddit, word_list, after, print_results=False, counter_dictionary=counter_dictionary)

    # Print formatted counter dictionary only if it's the top level call
    if print_results:
        for keyword in sorted(counter_dictionary, key=counter_dictionary.get, reverse=True):
            if counter_dictionary[keyword] != 0:
                print(f'{keyword}: {counter_dictionary[keyword]}')
