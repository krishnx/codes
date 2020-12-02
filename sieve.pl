#!/usr/perl/bin

use strict;

my $MAX = 101;
my @sieve;

for(my $i=2; $i<$MAX; $i++){
    $sieve[$i]=1;
}

$sieve[0]=0;
$sieve[1]=0;
my $primecount=0;
my @prime;

for(my $i=2; $i<$MAX; $i++){
    while($sieve[$i]==0 && $i<$MAX)
    {
	$i++;
    }
    $prime[$primecount]=$i;
    for(my $j=2*$i; $j<$MAX; $j+=$i) 
    {
	$sieve[$j]=0;
    }
    $primecount++;
}

print $primecount."\n";
for(my $i=0; $i<scalar(@sieve); $i++) {
    print "$i " if($sieve[$i] == 1);
    print "\n" if($i % 10 == 0);
}
