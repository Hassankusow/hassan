#include <stdio.h>
#include <assert.h>

char *index(const char *, int c);
char *rindex(const char *, int c);

char *
index(const char *s, int  c)
{
    if(s == NULL){
	return NULL;
    }
    else {
	    assert(s != NULL);}
  //  const char *a = NULL;
    while (*s != '\0') {
        if (*s == c) {
           return (char *)s; 
        }
        s++;
    }
       
   
 
    return NULL;   

}

char *
rindex(const char *s, int c)
{
     if(s == NULL){
        return NULL;
    }
    else {
            assert(s != NULL);}

    const char *l= NULL;

    while (*s != '\0') {
        if (*s == c) {
            l = s;
        }
        s++;
    }
    
    return (char *)l;

}

int
main(void)
{
    {
        char *str = "abcdefghijk abcdefghijK";

        char *a_addr = index(str, 'a');
        char *j_addr = index(str, 'j');
        char *K_addr = index(str, 'K');
        char *z_addr = index(str, 'z');
        char *null_addr = index(NULL, 'a');
        char *empty_addr = index("", 'a');

        assert(a_addr == &(str[0]));
        assert(j_addr == &(str[9]));
        assert(K_addr == &(str[22]));
        assert(z_addr == NULL);
        assert(null_addr == NULL);
        assert(empty_addr == NULL);

        printf("  all index tests pass\n");
    }
    {
          char *str = "Abcdefghijk abcdefghijk";

          char *k_addr = rindex(str, 'k');
          char *a_addr = rindex(str, 'a');
          char *j_addr = rindex(str, 'j');
          char *A_addr = rindex(str, 'A');
          char *z_addr = rindex(str, 'z');
          char *null_addr = rindex(NULL, 'a');
          char *empty_addr = rindex("", 'a');

          assert(k_addr == &(str[22]));
          assert(a_addr == &(str[12]));
          assert(j_addr == &(str[21]));
          assert(A_addr == &(str[0]));
          assert(z_addr == NULL);
          assert(null_addr == NULL);
          assert(empty_addr == NULL);

        printf("  all rindex tests pass\n");
    }

    printf("all tests pass\n");

    return 0;
}
