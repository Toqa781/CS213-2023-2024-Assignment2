void pattern( int star, int blank )
{
   if ( star == 0 )
     return;

   pattern( star/2, blank );

   for ( int i = 0; i < blank; i++ )
      cout << "  ";
   for ( int i = 0; i < star  ; i++ )
      cout << "* ";
   cout << endl;

   pattern( star/2, blank + star/2 );
}
int main(){
   int n;
   cout << "Enter an integer: ";
   cin >> n;
   pattern( n, 0 );
}
