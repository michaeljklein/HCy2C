


Depricated or comment code (for debugging or understanding intermediate steps in the writing of this program):

-- int counter2 (uint64_t* buf){
--     uint64_t cnt[buflen];
--     for (int i = 0; i < (buflen); i++) {
--         cnt[i] = 0;
--     }
--     __asm__(
--             "popcnt %4, %4  \n\t"
--             "add %4, %0     \n\t"
--             "popcnt %5, %5  \n\t"
--             "add %5, %1     \n\t"
--             "popcnt %6, %6  \n\t"
--             "add %6, %2     \n\t"
--             "popcnt %7, %7  \n\t"
--             "add %7, %3     \n\t" // +r means input/output, r means intput
--             : "+r" (cnt[0]), "+r" (cnt[1]), "+r" (cnt[2]), "+r" (cnt[3])
--             : "r"  (buf[0]), "r"  (buf[1]), "r"  (buf[2]), "r"  (buf[3]));
--     __asm__(
--             "popcnt %2, %2  \n\t"
--             "add %2, %0     \n\t"
--             "popcnt %3, %3  \n\t"
--             "add %3, %1     \n\t"
--             : "+r" (cnt[4]), "+r" (cnt[5])
--             : "r"  (buf[4]), "r"  (buf[5]));
--     __asm__(
--             "popcnt %1, %1  \n\t"
--             "add %1, %0     \n\t"
--             : "+r" (cnt[6])
--             : "r"  (buf[6]));

--     return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6];
-- }