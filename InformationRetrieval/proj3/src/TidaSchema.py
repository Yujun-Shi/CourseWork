from whoosh.fields import SchemaClass, TEXT, KEYWORD, ID, STORED
from jieba.analyse import ChineseAnalyzer


class TidaSchema(SchemaClass):
    pageURL = ID(stored = True, unique = True)
    anchorText = TEXT(stored = True,analyzer=ChineseAnalyzer())
    fullText = TEXT(stored = True, analyzer=ChineseAnalyzer())
    title = TEXT(stored = True, analyzer=ChineseAnalyzer())
