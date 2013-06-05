// Link: http://www.hpenterprisesecurity.com/vulncat/en/vulncat/cpp/use_after_free.html
//
// Abstract
//
// Referencing memory after it has been freed can cause a program to crash. 

char* ptr = (char*)malloc(SIZE);
...
if (err) {
  abrt = 1;
  free(ptr);
}
...
if (abrt) {
  logError("operation aborted before commit", ptr);
}
