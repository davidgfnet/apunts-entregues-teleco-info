#ifndef STATS_H
#define STATS_H

/* Structure used by 'get_stats' function */
struct stats {
       int total_tics; /* Total tics executed by the process */
       int total_trans;   /* Total transitions ready to run */
       int remaining_tics; /* Remaining tics to end the quantum */
};
#endif /* !STATS_H */
