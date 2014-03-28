//Simple XML Parser

extern NSString *const SimpleXMLDocumentErrorDomain;

@class SimpleXMLDocument;

@interface SimpleXMLElement : NSObject<NSXMLParserDelegate>

@property (nonatomic, weak) SimpleXMLDocument *document;
@property (nonatomic, weak) SimpleXMLElement *parent;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, retain) NSString *value;
@property (nonatomic, retain) NSArray *children;
@property (nonatomic, retain) NSDictionary *attributes;
@property (nonatomic, readonly) SimpleXMLElement *firstChild, *lastChild;

- (id)initWithDocument:(SimpleXMLDocument *)document;
- (SimpleXMLElement *)childNamed:(NSString *)name;
- (NSArray *)childrenNamed:(NSString *)name;
- (SimpleXMLElement *)childWithAttribute:(NSString *)attributeName value:(NSString *)attributeValue;
- (NSString *)attributeNamed:(NSString *)name;
- (SimpleXMLElement *)descendantWithPath:(NSString *)path;
- (NSString *)valueWithPath:(NSString *)path;

@end

@interface SimpleXMLDocument : NSObject<NSXMLParserDelegate>

@property (nonatomic, retain) SimpleXMLElement *root;
@property (nonatomic, retain) NSError *error;

- (id)initWithData:(NSData *)data error:(NSError **)outError;

- (NSString *)fullDescription; // like -description, this writes the document out to an XML string, but doesn't truncate the node values.

+ (SimpleXMLDocument *)documentWithData:(NSData *)data error:(NSError **)outError;

@end
