#!/usr/bin/python3
"""A recursive function that queries the Reddit API,
parses the title of all hot articles,
and prints a sorted count of given keywords
"""

import os
import requests


def count_words(subreddit, word_list):
    """
    Args:
            subreddit (str): subreddit to query
            word_list (list of str): the list of keywords to count

    Returns:
            nothing;
    """
    
    # Basic validation
    if (subreddit is None or 
        subreddit == "" or
        word_list is None or
        word_list == []):
            return
    
    # Getting API credentials
    # secret = os.environ["SECRET"]
    # personal_id = os.environ["PERSONAL_ID"]
    
    # url = "https://www.reddit.com/api/v1/access_token"
    # auth = requests.auth.HTTPBasicAuth(personal_id, secret)
    # headers_access = {"Content-Type": 'application/x-www-form-urlencoded', "User-Agent": "Vladimir_Davidov"}
    # data_access = 'grant_type=client_credentials'
    
    # token = requests.post(url, auth=auth, data=data_access, headers=headers_access)
    # access_token = token.json()['access_token']
    
    # Get the data
    # fetch_data_headers = {"User-Agent": "Vladimir_Davidov", "Authorization": access_token}
    
    # Fetching data
    url_access = f'https://reddit.com/r/{subreddit}/hot.json'
    response = requests.get(url_access)
    
    if response.status_code != 200:
        return
 
    data = response.json()["data"]['children']
    
    for thread in data:
        print("---" + thread['data']['title'])
