import configparser
import requests
import base64

consumer_key = 'R7UdLqOefMzHND0gJ8k7cV9tw'
consumer_secret = 'C41jYgKDTYiAJwlnBnumoENFBrikglnH3HKB6qxRkRoViPbWML'

key_secret = base64.urlsafe_b64encode('{}:{}'.format(consumer_key, consumer_secret).encode('ascii')).decode('ascii')

base_url = 'https://api.twitter.com/'
auth_url = '{}oauth2/token'.format(base_url)
auth_headers = {
    'Authorization': 'Basic {}'.format(key_secret),
    'Content-Type': 'application/x-www-form-urlencoded;charset=UTF-8'
}
auth_data = {
    'grant_type': 'client_credentials'
}

auth_resp = requests.post(auth_url, headers=auth_headers, data=auth_data)
print(auth_resp.status_code)
print(resp.status, resp.reason)