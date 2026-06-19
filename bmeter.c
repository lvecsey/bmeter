
#include <stdio.h>
#include <stdlib.h>

#include <getopt.h>

#include <errno.h>

#include <unistd.h>

#include <string.h>

int main(int argc, char *argv[]) {

  enum { INHALE, HOLD, EXHALE };

  double timings[3] = { 4, 7, 8 };

  long int sec_idx;

  long int repeat_count;
  
  int flags, opt;

  int retval;

  int c;
  int digit_optind = 0;

  repeat_count = 0;
  
  while (1) {
    int this_option_optind = optind ? optind : 1;
    int option_index = 0;
    static struct option long_options[] = {
      {"repeat",     required_argument, 0,  0 },
      {0,         0,                 0,  0 }
    };

    c = getopt_long(argc, argv, "",
		    long_options, &option_index);
    if (c == -1)
      break;

    switch (c) {
    case 0:

      if (!strncmp(long_options[option_index].name, "repeat", 6)) {
	if (optarg) {
	  repeat_count = strtol(optarg, NULL, 10);
	}
      }
      
      break;

    case '?':
      break;

    default:
      printf("?? getopt returned character code 0%o ??\n", c);
    }
  }

  while (repeat_count > 0) {
  
    for (sec_idx = 0; sec_idx < timings[INHALE]; sec_idx++) {
      putchar('I');
      fflush(stdout);
      usleep(1000000);
    }

    for (sec_idx = 0; sec_idx < timings[HOLD]; sec_idx++) {
      putchar('H');
      fflush(stdout);
      usleep(1000000);
    }

    for (sec_idx = 0; sec_idx < timings[EXHALE]; sec_idx++) {
      putchar('E');
      fflush(stdout);
      usleep(1000000);
    }

    putchar('\n');
    fflush(stdout);
      
    repeat_count--;
    
  }
    
  return 0;

}
