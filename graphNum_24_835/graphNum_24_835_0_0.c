#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_24_835_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 23;
static uint_fast32_t endhere = 0;
char str[34] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[24][11] = {{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU,0LLU,18158513697557839872LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,140737488355327LLU,0LLU,0LLU,18446744073709551360LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{0LLU,0LLU,18446603336221196288LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{0LLU,18446744004990074880LLU,18442240474082181119LLU,4611677222334365695LLU,18446744072635809792LLU,18446744073709486079LLU,18446744073709551615LLU,252201579132747775LLU,18446744004990074880LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,68719476735LLU,18446321861244485632LLU,18446743936270598143LLU,18446744073709551615LLU,18446440539494545919LLU,13473568300545587963LLU,18444439218160335871LLU,68719476735LLU,18446744073709535232LLU,17592186044415LLU},{18445618173802708992LLU,18446726481523507199LLU,18374686477524172799LLU,4322320121507346429LLU,17298326168730058752LLU,18446638520492621823LLU,16717335428117555199LLU,251146047968509951LLU,18446744073709518848LLU,18446744039349829631LLU,17592186044415LLU},{1125899906842623LLU,9223512568184700928LLU,16134708615008223231LLU,18428659302152503167LLU,18446743525027495935LLU,18446743661392594943LLU,18439988571187707879LLU,18446744047939741695LLU,18446744004990107647LLU,18374686514031362047LLU,17592186044415LLU},{1125899772624896LLU,9223319256001675260LLU,18446744071562067968LLU,4611674610994249727LLU,17296074918668025792LLU,14969965161379528703LLU,18446744073709551615LLU,238444489377578959LLU,18446744073701195712LLU,72057593970834975LLU,17592186044400LLU},{18445618173936926719LLU,18446743781085528575LLU,4505851427184181247LLU,18048878618418148605LLU,18446744073709535295LLU,18446630274147057663LLU,16582225377680680479LLU,18445899133381648383LLU,15987178184349024319LLU,18446744039416922109LLU,17592185978895LLU},{18159635212303056896LLU,9187422400373866367LLU,18446743526092865408LLU,4611674576634511359LLU,2238219163539356732LLU,17293822569102704638LLU,18446744073709551615LLU,238436243308806127LLU,18446744073205741694LLU,9294901865309290271LLU,17592177721343LLU},{288230375749074943LLU,18446743523953737716LLU,17329851363982540927LLU,18438299823401583615LLU,17363698732067192771LLU,16122886631635025919LLU,18446183322779255295LLU,18446744073407692767LLU,4557430892024823745LLU,9223372031085510399LLU,17591120691184LLU},{14106333697985085312LLU,8680763043748785983LLU,18446735795033766008LLU,4611674575560769535LLU,11299100896533885747LLU,18446744073709551603LLU,18446744073709551615LLU,14073494296477040639LLU,18446744070385985139LLU,17362396910291009439LLU,17576078934012LLU},{18176523972361797759LLU,18412965976988711919LLU,1152920989202907015LLU,16149908263750598624LLU,9169267242854841596LLU,17149707415386587134LLU,562949953421311LLU,4611686018427387886LLU,18446727580632087038LLU,10375862386738593648LLU,17334480664543LLU},{17433981662733524976LLU,4485162981933400061LLU,18446671773274357310LLU,13835058055282163711LLU,16064197447495957435LLU,144115188075855867LLU,18446744065119617024LLU,17532258810297581567LLU,18446744037969048410LLU,13581413916854927327LLU,16764326707190LLU},{10344644710200310415LLU,17433928932003473183LLU,18446728620181418481LLU,9223360593983963167LLU,4151450022776825446LLU,18446744073709551575LLU,18446744073709551615LLU,14987979559889010687LLU,18442258064052514551LLU,17579729951248940991LLU,14280748695357LLU},{6438275393886083036LLU,3110720664010866685LLU,18446650800629033771LLU,18446744073709551615LLU,18446744073709551615LLU,2251767595047935LLU,18446744073709551614LLU,7732426021139381761LLU,18446744027026948162LLU,11119985614238695423LLU,12913886298096LLU},{17868022676105854451LLU,18374268665169137215LLU,18446742969886113534LLU,11529215046072664063LLU,16064197447495957435LLU,18446744073709289467LLU,18446744065119617025LLU,17870283321406128127LLU,4503599627370495LLU,18302612376853118928LLU,8209729188095LLU},{18446744073709551613LLU,18446744069414584319LLU,18446744073709551615LLU,2305843009213693951LLU,0LLU,148618757634244352LLU,18446744073709551614LLU,7773064520691351043LLU,18446744027026948162LLU,11119985614238695423LLU,12913886298096LLU},{18446744073709551613LLU,140733193388031LLU,18446321861244485632LLU,18446743936270598143LLU,1073741823LLU,441352737712503552LLU,18446744073709551614LLU,18446702290254429703LLU,18446744073709551615LLU,11119985614238679055LLU,12913886298096LLU},{18445618190982578173LLU,18446743798831644671LLU,9195928226625519615LLU,18374404987481357823LLU,2251799813668927LLU,4503593013112994560LLU,18338656033360051838LLU,18446739261735468607LLU,15987178206377508991LLU,18446744056465097213LLU,12913886236671LLU},{18445618190982578173LLU,9223512293306794495LLU,18422677965348274175LLU,18446744073709551615LLU,1152920955928952895LLU,9151314442810465024LLU,18446744073709551614LLU,18446744072635809407LLU,18446744005006819455LLU,18374704071857652735LLU,12913886236671LLU},{287108873889251325LLU,9259399803085783028LLU,17846217758514053247LLU,18446744073709551615LLU,17363768584408646595LLU,18446744041490914049LLU,18446744073709551614LLU,18446744073709551359LLU,18446744005519050691LLU,18375249429562116095LLU,12912953335792LLU},{4340410385522705405LLU,9766053662182079460LLU,17846225489573152647LLU,18446744073709551599LLU,8302895647507139788LLU,18304880653228743438LLU,18446744073709551615LLU,9223372036854775807LLU,18446744008875678158LLU,11461238839140929535LLU,12712291549171LLU},{17651002176063622645LLU,11429781888744512228LLU,17846250877512228510LLU,11529232638254514159LLU,15450547071020013977LLU,18446744073709551418LLU,18446744073709551615LLU,18446744073709551615LLU,1152921452794330078LLU,13780720177717960688LLU,16595145421815LLU}};

static uint_fast64_t D[24][11] = {{12008468679957702885LLU,15336023491844129286LLU,17846310483977884884LLU,4611656983374725071LLU,1155257418133798912LLU,18446744073709551506LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{6438275393751848730LLU,3110720581865422329LLU,18446650800629033771LLU,18446744073709551615LLU,18446744073709551615LLU,18298875905273809407LLU,12297829382473034411LLU,18331215273071913980LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,600526862812184575LLU,13835087090334826544LLU,17291486655575752703LLU,147868168435742317LLU,6148914691236517204LLU,18274042498195477507LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,7880877135433302015LLU,17641970605549529530LLU,17291486655575752703LLU,440897436389734509LLU,10986980413963606136LLU,18299182595412883463LLU,68719476735LLU,18446744073709535232LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,11161608726484353023LLU,804793569680709237LLU,18446744072635809792LLU,18153411271540488191LLU,8635502577818499031LLU,224756626366126075LLU,18446744004990074880LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,9223512636904177663LLU,14841753309487824895LLU,17840903264475754299LLU,17293822020420632575LLU,8565423754404921453LLU,11520665113189261280LLU,18299248953463398519LLU,7378697670715506687LLU,18374686514031346662LLU,17592186044415LLU},{18446744073709551615LLU,18446726481523507199LLU,9106278444395692031LLU,17940369542399259132LLU,17295990256276865023LLU,10322111790160543743LLU,16176895226370056319LLU,18445622158724988815LLU,11068046471713521663LLU,18446744039349828633LLU,17592186044415LLU},{18446744073709551615LLU,18446743643646575103LLU,1117033445076238335LLU,18311108287031688255LLU,17293822569102704639LLU,9151305681075175533LLU,18303189645120372224LLU,18302628336951492735LLU,14757395250683052031LLU,18423628009966650364LLU,17592185978895LLU},{1125899906842623LLU,105548821299196LLU,18302628885633662976LLU,17868028085349117947LLU,18444492274965430271LLU,14384074988363710463LLU,11529109491341565951LLU,18429818191302623175LLU,8608480604373155839LLU,23116098102623751LLU,17592186044400LLU},{18446744073441116159LLU,18446743093890777079LLU,17293963306591059967LLU,18437772057757335615LLU,18446744073709551615LLU,18446744039349813357LLU,18446181132345933824LLU,18302628885600141567LLU,1085102574601764863LLU,18423657278759487487LLU,17591120632495LLU},{18446739688547942399LLU,18410847218081726847LLU,1152920956998516735LLU,18311636018316197887LLU,1152921472331676735LLU,9151305681083564030LLU,18303191835553693695LLU,18446735278690271103LLU,18229723567610656895LLU,18446187033631128572LLU,17592177714527LLU},{18446744072904212479LLU,18446741994408508391LLU,140737488355327LLU,16140936248867946464LLU,18446744073709551615LLU,18302628885633695855LLU,8589934591LLU,18302628885633695742LLU,1152903959665442815LLU,18424212662188494832LLU,17333607150543LLU},{14123222458580729855LLU,17906307719845900223LLU,18446735827246512255LLU,18446744071566245951LLU,18230148975849370611LLU,18446744073709551601LLU,18446744073709420544LLU,18446744071562068223LLU,18378926192748652531LLU,18442802048291305471LLU,17575895359164LLU},{13816973011263060735LLU,17868027259365618631LLU,131906900850679LLU,18446744073705357312LLU,8916546573738897134LLU,18446744073709551567LLU,8589934591LLU,18302628885633695742LLU,18442240538506690559LLU,18442239442283393023LLU,14207458197263LLU},{18302063736589901823LLU,13817043605230977021LLU,18446673429009514431LLU,16140936248867946495LLU,18446744073709551615LLU,127LLU,18446744065119617024LLU,18446744073709551615LLU,1152921452794330078LLU,13780720177717960688LLU,16595145421815LLU},{18446744056797625599LLU,18446603473634968071LLU,140737488355327LLU,16140901064495857664LLU,18446744073709551615LLU,18446744073709289471LLU,18446744073709551615LLU,18302628885633695743LLU,68719476735LLU,18446726533130223600LLU,6545404325903LLU},{2242545361723847647LLU,16421250132977254399LLU,18446713166653285347LLU,18446744073709551615LLU,8916546573738897134LLU,18304880653228743631LLU,8589934591LLU,8070450532247928320LLU,18446744058472484071LLU,15836696983390056447LLU,12021342650361LLU},{18446744056663391291LLU,18446603387194556419LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18445242895312743935LLU,12297829382473034411LLU,18227738584548027390LLU,68719476735LLU,18446726533130223600LLU,6545404325903LLU},{18446744056663391291LLU,18446744055963435011LLU,11161608726484353023LLU,16945694634176566901LLU,18446744073709551615LLU,18444947607436945407LLU,7459763659745945479LLU,10681693762316896254LLU,18446744051672678333LLU,18446726533130223615LLU,6545404325903LLU},{1125899906333755LLU,18446708889337462272LLU,15707992550314868735LLU,16692505152318295923LLU,18446744073705373695LLU,18444632597054089215LLU,2298559733057331175LLU,10665649791718909950LLU,8608480604364767229LLU,7349857034042343415LLU,6545404329983LLU},{18446744073709042747LLU,18446691297151418367LLU,17906312118425092095LLU,16276554478793245680LLU,18446659961070026751LLU,14967722155519508479LLU,143554428589179391LLU,10664532713404497870LLU,3689348869717491709LLU,7349874574753365523LLU,6545404329983LLU},{18446744069414583355LLU,18446682501058396031LLU,1152921504606846975LLU,16149890673707859952LLU,18446730329814204415LLU,17291570803648495615LLU,562941363617791LLU,10664523919760818158LLU,17361641545815556095LLU,16573234935003447056LLU,6545528452447LLU},{18446744067266969531LLU,18446678103011880767LLU,18446744073709551615LLU,18446726481523507263LLU,18446739125907226623LLU,18446744073709289471LLU,18446744065119617025LLU,15276209936040722943LLU,17293840161288749055LLU,17726164006134972319LLU,6586281360447LLU},{16131858543425879967LLU,18157387797382430719LLU,18446739658415799291LLU,18446744073705357375LLU,18446739675663040511LLU,18446744073709551615LLU,8589934591LLU,14699749183737298944LLU,18442258064052514551LLU,17579729951248940991LLU,14280748695357LLU}};

uint_fast8_t X[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[24][11] = {{12008468679957702885LLU,15336023491844129286LLU,17846310483977884884LLU,4611656983374725071LLU,1155257418133798912LLU,18446744073709551506LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU}};

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
    fputs("[[0,1],[0,8],[0,15],[1,2],[1,9],[2,3],[2,11],[3,4],[3,10],[4,5],[4,12],[5,6],[5,13],[6,7],[6,15],[7,8],[7,14],[8,9],[9,10],[10,11],[11,12],[12,13],[13,14],[14,15]]\n", fout);
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
