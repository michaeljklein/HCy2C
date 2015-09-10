#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_24_231_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 23;
static uint_fast32_t endhere = 0;
char str[34] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[24][14] = {{18446744073709551615LLU,18446744073709551615LLU,0LLU,18446744004990074880LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,0LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{0LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU,0LLU,18446744073709551360LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU,18446726481523507200LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU,0LLU,18446744073709486080LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU,18442240474082181120LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU,0LLU,18446744073692774400LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU,17293822569102704640LLU,4503599627370495LLU},{18446744073709551360LLU,18446744073709551615LLU,18446744073709551361LLU,18446726618962460671LLU,18446744073709551615LLU,18446744073709486591LLU,18442275658454269951LLU,18446744073709551615LLU,18446744073692905471LLU,17302829768357445631LLU,18446744073709551615LLU,18446744069448138751LLU,1152921504606846975LLU,4503599627370488LLU},{18446744073709486335LLU,18157383382357245949LLU,18446744073709551615LLU,18444509866081910783LLU,17284744451331194879LLU,17293822569094381559LLU,17874786366948898815LLU,16122745924203053055LLU,18446744071578843119LLU,1152779658949296111LLU,13799028158751571960LLU,18446743528248176607LLU,18410431585376530431LLU,4503599627369479LLU},{18446744073692839935LLU,17868022691005463547LLU,18442240474082148607LLU,18446744071545158647LLU,18446744073709551615LLU,16140901063430504447LLU,576459644134227951LLU,13799028150161637372LLU,18446743800979124191LLU,18446460382395494367LLU,9223088362854808583LLU,18446674254720131007LLU,18374119097310896127LLU,4503599627240447LLU},{18446744069431361535LLU,17289301308569286647LLU,17284815369843802111LLU,18160765493042739199LLU,16122745924169498623LLU,18446744073709551599LLU,18446744073709551615LLU,9223088345674939907LLU,18446709164215361471LLU,18446176691348823999LLU,18374119131671561215LLU,18437807243196874623LLU,18301494189363281919LLU,4503599610724351LLU},{18446742978492891135LLU,16131858680599539695LLU,16122886665453699071LLU,288230367494143983LLU,13799028150094528510LLU,13835057918916952031LLU,18446741857372205023LLU,18446744073709551615LLU,18442275658454269951LLU,18445609377439137663LLU,18301494189617184767LLU,17302829768353218558LLU,18156261828483579903LLU,4503597496664063LLU},{18446463698244468735LLU,13817043518794751967LLU,13799029190080593919LLU,18446744056395460575LLU,9223088345540722433LLU,9223354582107684799LLU,18446739641302245311LLU,18374119097311887871LLU,18446744073709535103LLU,18446744073709551615LLU,18156244303427403775LLU,1152921504598458109LLU,17870265590698934264LLU,4503326896947199LLU},{18374967954648334335LLU,9223301392154738623LLU,9151305715443302399LLU,18446744039348756415LLU,18374119097043484927LLU,18444509866081910655LLU,18446735277345980286LLU,18301494120906031103LLU,17874786921033465854LLU,18444492204635291391LLU,18446744073709551615LLU,18446744073709551615LLU,18442205012667792391LLU,4468690133188607LLU},{72057594037927935LLU,18410573987290513279LLU,18301511781819875327LLU,18446744073439002494LLU,18301494120373321727LLU,18160765497371525118LLU,18446744004448976637LLU,18156244167053803519LLU,576460752303423229LLU,18446726343002357244LLU,17865744264676245503LLU,18446744073709485563LLU,18446744073709551615LLU,35184372088831LLU},{18157383382357245949LLU,18446744073709486335LLU,18446744073709551615LLU,17284815094970056703LLU,18446743937344207863LLU,18437665951626296319LLU,16140830695751679491LLU,18446709164181551087LLU,16122744820396195839LLU,18428729675199939583LLU,18437807234541416415LLU,13798745584196124671LLU,17293822569069412319LLU,4432676798593023LLU},{17868022691005463547LLU,18446744073692839935LLU,288194914737324027LLU,18446744073709551614LLU,18446744073709551615LLU,18428587829609887743LLU,18428588937711649279LLU,18442275658386632671LLU,13798745584195600383LLU,13799029258246553599LLU,17302829751042301951LLU,9150751475549339647LLU,16140901060234444735LLU,4361753969819631LLU},{17289301308569286647LLU,18446744069431361535LLU,18446673150881037303LLU,16140830145995865857LLU,18446726618962196463LLU,18446744073709551615LLU,13798747783286489087LLU,17874786920898224127LLU,9150751475548291071LLU,9151314440686141439LLU,1152921469976575935LLU,18302624452959010808LLU,13835057509821316990LLU,4219908313313247LLU},{16131858680599539695LLU,18446742978492891135LLU,18446602228119369711LLU,18428587838200054015LLU,18444509866081382367LLU,18410431602622984191LLU,18446744073701228543LLU,18446744073709551615LLU,18302624452956913663LLU,18302628612903272446LLU,18446744004453187454LLU,18445609308453338119LLU,9223302217866411773LLU,3936217266642879LLU},{13817043518794751967LLU,18446463698244468735LLU,18446460399641948127LLU,13798745584259071999LLU,18160765497370468351LLU,18374123512403058687LLU,9150751491798073343LLU,576460752032890815LLU,18446744073709551612LLU,18158513697557839871LLU,18446743936266370813LLU,18156244167045284863LLU,18437807243198987775LLU,3368903356956542LLU},{9223301392154738623LLU,18374967954648334335LLU,18446181106440986559LLU,9150747094284238847LLU,288230376149614527LLU,18302624452956897278LLU,18301502849361641471LLU,18446744073172664190LLU,18445609308449144323LLU,18446709164215369725LLU,18446744073709551615LLU,17865744260381278207LLU,17302829768357445627LLU,2251730553110269LLU},{18410573987290513279LLU,72057594037927935LLU,18446739641032753023LLU,18301494121451225087LLU,18446744073709535102LLU,18445609308449111809LLU,18156244442997063679LLU,18446744073705324285LLU,18156244167036961279LLU,17865814906150846463LLU,18446744072627355131LLU,18446744073692905471LLU,18446744073709551615LLU,4485868920176123LLU}};

static uint_fast64_t D[24][14] = {{18157383382357245693LLU,18157383382357245693LLU,18446744073709551615LLU,17284797502784012287LLU,17284744450257320951LLU,17284744447019383799LLU,16136326542039709691LLU,16122745649291327471LLU,16122744820379416559LLU,17275666324935670767LLU,13798957781349822431LLU,13798745579900628959LLU,18410431585376268255LLU,4503599627370495LLU},{18302063728033398270LLU,18446744073709551615LLU,18445600443095514621LLU,17865744399967715327LLU,18446744073705291259LLU,18153974636516081151LLU,17284780185475874815LLU,18446744072618900471LLU,17284744447019319295LLU,16131893865241116667LLU,18446743794502858735LLU,16122744820362903551LLU,18446744073709550575LLU,4503599627370495LLU},{18446744073709551615LLU,18302063728033398270LLU,17868031521592442878LLU,18446744003907878395LLU,17865744260372889599LLU,17870283321406127867LLU,18446726204481207287LLU,17284744449200488447LLU,18446744073709485047LLU,18442169551253403639LLU,16122745378742206463LLU,18446744073692510191LLU,18428587829542516735LLU,4503599627370495LLU},{17868022691005398011LLU,17868022691005398011LLU,18153974636516081403LLU,18446744071545158647LLU,18446744073709551615LLU,16122744820387805183LLU,17852127077239094767LLU,13798992965721911263LLU,13798745582048112607LLU,13798745566949011423LLU,9214081146284924919LLU,9150750925792468927LLU,18374119097277341631LLU,4503599627370495LLU},{17289301308552509431LLU,17289301308552509431LLU,17284744447019416567LLU,16138578341853394941LLU,16122745786730280943LLU,18446744073709551599LLU,13798747783286489087LLU,9218584745912295419LLU,9150751200670375871LLU,9150747060439343039LLU,17221197592434572223LLU,18302554084212719487LLU,18301494185068314494LLU,4503599627370495LLU},{16131858676304572399LLU,16131858676304572399LLU,16122744820391999471LLU,18140357453390806767LLU,13799010557907955679LLU,13798745583121854431LLU,18446741857372139487LLU,18446744073709551615LLU,18302589268584824831LLU,18301494187215798142LLU,18301494120377335678LLU,18436602109194371062LLU,18156261278727765757LLU,4503599627370495LLU},{13817042419283124191LLU,13817042419283124191LLU,13798745583658725343LLU,13798745566949109727LLU,9220836545725980669LLU,9150751338109329343LLU,9150747060447731647LLU,17797658344737996223LLU,18446744073709535103LLU,18158513697557839871LLU,18156244168098152189LLU,17003322662430178045LLU,17870195221954756095LLU,4503599627370495LLU},{9223019917178027967LLU,9223019917178027967LLU,9150751406828806079LLU,9150747060451925951LLU,18085888720889708223LLU,18302606860770852735LLU,18301494188289539966LLU,18301494120377401214LLU,18441105708821741562LLU,18444491929757384445LLU,18446744073709551615LLU,17865744260381278207LLU,18433197813413052403LLU,4503599627370495LLU},{18338516393252585343LLU,18338516393252585343LLU,18302615656863874943LLU,18301494188826410878LLU,18301494120377433982LLU,18443357508635426812LLU,18156261691044626173LLU,18156244168106540797LLU,17579783414733602045LLU,17870230406326844927LLU,17865744534176988667LLU,18446744073709354491LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551360LLU,18160765497371525119LLU,18446744073709551615LLU,18446744072644198399LLU,576460752303423487LLU,18446744073709551612LLU,18446743800979128319LLU,18446744073709551615LLU,18446744073709550599LLU,18446674254721187839LLU,18446744073709551615LLU,18446744073709291519LLU,4468138212981751LLU},{18446744073709551615LLU,18446744073709486591LLU,18445618173802708992LLU,18446744073709551615LLU,18446743938418081791LLU,18446744073709551615LLU,18446744073709551111LLU,18446709439093276671LLU,18446744073709551615LLU,18446744073709422591LLU,18437877611943165951LLU,18446744073709551615LLU,17293822569069674495LLU,4432676798593023LLU},{18446744073709551615LLU,18446744073692905471LLU,576460752303423487LLU,68719476734LLU,18446744073705357312LLU,18446744073709551615LLU,18446744073709487103LLU,18442310842826358783LLU,18446744073709551615LLU,18446744073693036543LLU,17311836967612186623LLU,18446744073709551615LLU,16140901060267999231LLU,4361753969819631LLU},{18446744073709551615LLU,18446744069448138751LLU,18446744073709551615LLU,18446744073709551363LLU,18446726756401414143LLU,18158513697557840127LLU,18446744073709551615LLU,17879290520660869119LLU,18446744073709551615LLU,18446744071595622399LLU,2305843009213693951LLU,18446744073709551608LLU,13835057514116284415LLU,4219908313313247LLU},{18446744073709551615LLU,18446742982787858431LLU,18446744073709551615LLU,18446744073709519359LLU,18444527458267955199LLU,18446744073709551615LLU,17592177786879LLU,18446744072635809792LLU,18446744073709551615LLU,18446743803126611967LLU,18446744073709551615LLU,18446744073709550607LLU,9223302767622225919LLU,3936217266642879LLU},{18446744073709551615LLU,18446464797756096511LLU,18446744073709551615LLU,18446744073705422847LLU,18163017297185210367LLU,18446744073709551615LLU,18446744072652587007LLU,1152921504606846975LLU,65532LLU,18446744073709551612LLU,18446744073709551615LLU,18446744073709422591LLU,18437877611943165951LLU,3368903356956542LLU},{18446744073709551615LLU,18375249429625044991LLU,18446744073709551615LLU,18446744073181069311LLU,576460752303423487LLU,18446744073709551614LLU,18446743938418081791LLU,18446744073709551615LLU,18446744073709551111LLU,4468965011095551LLU,18446743798831644672LLU,18446744073709551615LLU,17311836967612186623LLU,2251730553110269LLU},{18446744073709551615LLU,144115188075855871LLU,18446744073709551615LLU,18446744006063816703LLU,18446744073709551615LLU,18446744073709551363LLU,18446726756401414143LLU,18446744073709551615LLU,18446744073709487103LLU,18442310842826358783LLU,18446744073709551615LLU,262143LLU,18446744073709550592LLU,4485868920176123LLU},{18446744073709486591LLU,18446744073709551615LLU,1125899906842623LLU,18444527389548478464LLU,18446744073709551615LLU,18446744073701294079LLU,17879290520660869119LLU,18446744073709551615LLU,18446744071595622399LLU,2305843009213693951LLU,18446744073709551608LLU,18446743532543672319LLU,18446744073709551615LLU,4503599627369479LLU},{18446744073692905471LLU,18446744073709551615LLU,18446744073709519359LLU,18446744073709551615LLU,4194303LLU,18446744072652586752LLU,1152921504606846975LLU,18446744073709551612LLU,18446743803126611967LLU,18446744073709551615LLU,18446744073709550607LLU,18446674804477001727LLU,18446744073709551615LLU,4503599627240447LLU},{18446744069448138751LLU,18446744073709551615LLU,18446744073705422847LLU,18163017297185210367LLU,18446744073709551615LLU,288230376151711743LLU,18446726481523507200LLU,18446744073709551111LLU,18446709439093276671LLU,18446744073709551615LLU,18446744073709422591LLU,18437877611943165951LLU,18446744073709551615LLU,4503599610724351LLU},{18446742982787858431LLU,18446744073709551615LLU,18446744073181069311LLU,576460752303423487LLU,18446744073709551614LLU,18446743938418081791LLU,18446744073709551615LLU,1073741823LLU,18442310842826293248LLU,18446744073709551615LLU,18446744073693036543LLU,17311836967612186623LLU,18446744073709551615LLU,4503597496664063LLU},{18446464797756096511LLU,18446744073709551615LLU,18446744006063816703LLU,18446744073709551615LLU,18446744073709551363LLU,18446726756401414143LLU,18446744073709551615LLU,18446744073709487103LLU,18446744073709551615LLU,18442240474082181123LLU,18446744071595622399LLU,2305843009213693951LLU,18446744073709551608LLU,4503326896947199LLU},{18375249429625044991LLU,18446744073709551615LLU,18446735415055482879LLU,18446744073709551615LLU,18446744073709519359LLU,18444527458267955199LLU,18446744073709551615LLU,18446744073701294079LLU,17879290520660869119LLU,18446744073709551615LLU,274877906943LLU,18446744073692774400LLU,18446744073709550607LLU,4468690133188607LLU},{144115188075855871LLU,18446744073709551615LLU,18445635765988753407LLU,18446744073709551615LLU,18446744073705422847LLU,18163017297185210367LLU,18446744073709551615LLU,18446744072652587007LLU,1152921504606846975LLU,18446744073709551612LLU,18446743803126611967LLU,18446744073709551615LLU,17293822569102705663LLU,35184372088831LLU}};

uint_fast8_t X[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[24][14] = {{18157383382357245693LLU,18157383382357245693LLU,18446744073709551615LLU,17284797502784012287LLU,17284744450257320951LLU,17284744447019383799LLU,16136326542039709691LLU,16122745649291327471LLU,16122744820379416559LLU,17275666324935670767LLU,13798957781349822431LLU,13798745579900628959LLU,18410431585376268255LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[24];
    cnt[0] = 0;
    cnt[1] = 0;
    cnt[2] = 0;
    cnt[3] = 0;
    cnt[4] = 0;
    cnt[5] = 0;
    cnt[6] = 0;
    cnt[7] = 0;
    cnt[8] = 0;
    cnt[9] = 0;
    cnt[10] = 0;
    cnt[11] = 0;
    cnt[12] = 0;
    cnt[13] = 0;
    cnt[14] = 0;
    cnt[15] = 0;
    cnt[16] = 0;
    cnt[17] = 0;
    cnt[18] = 0;
    cnt[19] = 0;
    cnt[20] = 0;
    cnt[21] = 0;
    cnt[22] = 0;
    cnt[23] = 0;

    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[0]), "+r" (cnt[1]), "+r" (cnt[2]), "+r" (cnt[3])
            : "r" (buf[0]), "r" (buf[1]), "r" (buf[2]), "r" (buf[3]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[4]), "+r" (cnt[5]), "+r" (cnt[6]), "+r" (cnt[7])
            : "r" (buf[4]), "r" (buf[5]), "r" (buf[6]), "r" (buf[7]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[8]), "+r" (cnt[9]), "+r" (cnt[10]), "+r" (cnt[11])
            : "r" (buf[8]), "r" (buf[9]), "r" (buf[10]), "r" (buf[11]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[12]), "+r" (cnt[13]), "+r" (cnt[14]), "+r" (cnt[15])
            : "r" (buf[12]), "r" (buf[13]), "r" (buf[14]), "r" (buf[15]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[16]), "+r" (cnt[17]), "+r" (cnt[18]), "+r" (cnt[19])
            : "r" (buf[16]), "r" (buf[17]), "r" (buf[18]), "r" (buf[19]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[20]), "+r" (cnt[21]), "+r" (cnt[22]), "+r" (cnt[23])
            : "r" (buf[20]), "r" (buf[21]), "r" (buf[22]), "r" (buf[23]));


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14] + cnt[15] + cnt[16] + cnt[17] + cnt[18] + cnt[19] + cnt[20] + cnt[21] + cnt[22] + cnt[23];
}

#elif UINTPTR_MAX == 0xffffffff // 32-bit
int counter (unsigned long long i)
{
  unsigned int i1 = i, i2 = i >> 32;
  i1 = i1 - ((i1 >> 1) & 0x55555555);
  i2 = i2 - ((i2 >> 1) & 0x55555555);
  i1 = (i1 & 0x33333333) + ((i1 >> 2) & 0x33333333);
  i2 = (i2 & 0x33333333) + ((i2 >> 2) & 0x33333333);
  i1 = (i1 + (i1 >> 4)) & 0xF0F0F0F;
  i2 = (i2 + (i2 >> 4)) & 0xF0F0F0F;
  return ((i1 + i2) * 0x1010101) >> 24;
}

#else
#error "this cpu doesn't seem to be 32-bit or 64-bit. I don't know how to deal with this."
#endif
void f(uint_fast8_t i, uint_fast8_t y0){
    if(y0){
        A[i][0] = A[i-1][0] & C[i][0];
        A[i][1] = A[i-1][1] & C[i][1];
        A[i][2] = A[i-1][2] & C[i][2];
        A[i][3] = A[i-1][3] & C[i][3];
        A[i][4] = A[i-1][4] & C[i][4];
        A[i][5] = A[i-1][5] & C[i][5];
        A[i][6] = A[i-1][6] & C[i][6];
        A[i][7] = A[i-1][7] & C[i][7];
        A[i][8] = A[i-1][8] & C[i][8];
        A[i][9] = A[i-1][9] & C[i][9];
        A[i][10] = A[i-1][10] & C[i][10];
        A[i][11] = A[i-1][11] & C[i][11];
        A[i][12] = A[i-1][12] & C[i][12];
        A[i][13] = A[i-1][13] & C[i][13];

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];
        A[i][4] = A[i-1][4] & D[i][4];
        A[i][5] = A[i-1][5] & D[i][5];
        A[i][6] = A[i-1][6] & D[i][6];
        A[i][7] = A[i-1][7] & D[i][7];
        A[i][8] = A[i-1][8] & D[i][8];
        A[i][9] = A[i-1][9] & D[i][9];
        A[i][10] = A[i-1][10] & D[i][10];
        A[i][11] = A[i-1][11] & D[i][11];
        A[i][12] = A[i-1][12] & D[i][12];
        A[i][13] = A[i-1][13] & D[i][13];

    }
}

void printout(){
    sprintf(str, "[                        ,%5d]\n", this);
    str[1] = X[0] ^ 48;
    str[2] = X[1] ^ 48;
    str[3] = X[2] ^ 48;
    str[4] = X[3] ^ 48;
    str[5] = X[4] ^ 48;
    str[6] = X[5] ^ 48;
    str[7] = X[6] ^ 48;
    str[8] = X[7] ^ 48;
    str[9] = X[8] ^ 48;
    str[10] = X[9] ^ 48;
    str[11] = X[10] ^ 48;
    str[12] = X[11] ^ 48;
    str[13] = X[12] ^ 48;
    str[14] = X[13] ^ 48;
    str[15] = X[14] ^ 48;
    str[16] = X[15] ^ 48;
    str[17] = X[16] ^ 48;
    str[18] = X[17] ^ 48;
    str[19] = X[18] ^ 48;
    str[20] = X[19] ^ 48;
    str[21] = X[20] ^ 48;
    str[22] = X[21] ^ 48;
    str[23] = X[22] ^ 48;
    str[24] = X[23] ^ 48;

}


void checkifbest(){
    uint_fast64_t * thisbuf = A[maxpos];
    this = counter(thisbuf);

    if(this == best){
        printout();
        fwrite(str, 1, sizeof(str), fout);
    }

    if(this > best){
        printout();
        fwrite(str, 1, sizeof(str), fout);
        best = this;
    }

}

int r(){
    goto startnocarry;
    
    startnocarry:
        if(i == maxpos){
            if(X[i]){
                X[i] = 0;
                i--;
                goto startcarry;
            }else{
                f(i, 0);
                checkifbest();
                X[i] = 1;
                f(i, 1);
                checkifbest();
                X[i] = 0;
                i--;
                goto startcarry;
            }
        }else{
            f(i, X[i]);
            i++;
            goto startnocarry;
        }
        
    startcarry:
        if(X[i] && (i != endhere)){
            X[i] = 0;
            i--;
            goto startcarry;
        }else{
            if(i == endhere){
                goto end;
            }else{
                X[i] = 1;
                f(i, 1);
                i++;
                goto startnocarry;
            }
        }

    end:
        return 0;
}
int main(){
fout = fopener;
    fputs("[[0,1],[0,2],[0,3],[0,4],[0,5],[0,6],[0,7],[0,8],[0,9],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7],[1,8],[1,9],[2,3],[2,4],[2,5],[2,6],[2,7],[2,8],[2,9]]\n", fout);
    if(endhere){
        uint_fast8_t bitpos = 0;
        uint_fast8_t thisbit;
        while(starthere){
            thisbit = starthere & 1;
            X[bitpos] = thisbit;
            f(bitpos, thisbit);
            bitpos++;
            starthere >>= 1;
        }
        i = endhere;
        r();
    }else{
        i = 0;
        r();
    }
    fwrite("FINISHED.", 1, 9, fout);
    fclose(fout);
    return 0;
}
