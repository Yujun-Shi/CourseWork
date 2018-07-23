# A Simple Search Engine



## 1. About

This is a simple search engine implemented in python. It is based on the python library whoosh.



## 2. How to Use

First, execute the file "crawl.sh". This file will use "wget" to crawl files from some websites.

```bash
./crawl.sh
```

Then, after obtaining the data, execute the following to build the index on crawled html files.

```bash
python build.py
```

Finally, do the query

If you want to use the command line to query, then execute

```bash
python query.py
```

If you want to do query in browser like google, then, first execute

```bash
python web.py
```

Then, open your browser and navigate to the address: 127.0.0.1:3434

Then, a web interface will pop out and you can make your queries.

