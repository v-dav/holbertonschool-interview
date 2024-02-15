# Log Parsing

![Python](https://img.shields.io/badge/Python-Algorithms-blue?style=for-the-badge&logo=python&logoColor=white)

![1356089c-b0ea-475f-a30e-e5507ac04cc9](https://github.com/v-dav/holbertonschool-interview/assets/115344057/ef9f666c-1716-4a59-ae5f-bb0a93caafbd)


## 🧐 Project Overview

Welcome to the "Log Parsing" project! This script reads stdin line by line and computes metrics based on the provided input format. The metrics include total file size and the number of lines per status code.

## ⚙️ Task Details

Write a script that reads stdin line by line and computes metrics:

- **Input Format:** `<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>`
  (If the format is not this one, the line must be skipped)

- After every 10 lines and/or a keyboard interruption (CTRL + C), print these statistics from the beginning:
  - Total file size: File size: `<total size>` where `<total size>` is the sum of all previous `<file size>`
  - Number of lines by status code (possible status codes: 200, 301, 400, 401, 403, 404, 405, 500)

## 🧑🏼‍💻 Example

```bash
$ ./0-generator.py | ./0-stats.py

File size: 5213
200: 2
401: 1
403: 2
404: 1
405: 1
500: 3

File size: 11320
200: 3
301: 2
400: 1
401: 2
403: 3
404: 4
405: 2
500: 3

File size: 16305
200: 3
301: 3
400: 4
401: 2
403: 5
404: 5
405: 4
500: 4

^CFile size: 17146
200: 4
301: 3
400: 4
401: 2
403: 6
404: 6
405: 4
500: 4
```

##  🙇 Author

[Vladimir Davidov](https://github.com/v-dav) - Holberton School
