#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_18_1984_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 17;
static uint_fast32_t endhere = 0;
char str[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[18][15] = {{0LLU,0LLU,18446744073701163008LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,8388607LLU,0LLU,18446673704965373952LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU,0LLU,0LLU,18446744073709551584LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,31LLU,0LLU,18446744073441116160LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU,0LLU,18446744069414584320LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744065128005631LLU,18446709849799524227LLU,18302697598667864039LLU,9223372036854775807LLU,7962363161728679920LLU,18446744073709486095LLU,10230418310017581055LLU,18446744039479263231LLU,9223125332319010815LLU,3120561262LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446471394825862144LLU,18189986118387220287LLU,18446744073709354239LLU,18446744073709551615LLU,144115188075855871LLU,17279742222157217776LLU,18441810565035720703LLU,18438018349297369082LLU,9223372036854245116LLU,17437933393449842492LLU,17183765853208831975LLU,18446744073704956927LLU,18446744069414584320LLU,18446744073709551615LLU,4194303LLU},{18446744073707455487LLU,16428355159538532351LLU,18446726490110558141LLU,18229480576061014015LLU,18446719883899174558LLU,18446744073709551615LLU,18446744073709551615LLU,18167520759507845119LLU,18421974271598174207LLU,10375734989554515171LLU,18446738026366148607LLU,18446744073305268223LLU,4294967295LLU,18446744073709551615LLU,4194303LLU},{16708636088228380671LLU,2305843009213691127LLU,18410732868876620779LLU,18446744050019332223LLU,18446743979045158911LLU,18248585656819236879LLU,18012648084017774095LLU,18446744073709551615LLU,18446744073709551615LLU,9151877392770269183LLU,17998635886928985756LLU,18446744073709551609LLU,18446744073709551615LLU,18446744069414584320LLU,4194303LLU},{11249987475419955199LLU,18446743691591679998LLU,36028797018963967LLU,15241307038916939774LLU,18446744073709551615LLU,18446646251517657087LLU,18446744073708093951LLU,9511461812957085695LLU,18446731845937659859LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17293822573397671935LLU,4194303LLU},{4398046511103LLU,18446744073709486080LLU,18297914179656351743LLU,10371783344764485630LLU,18446707789620280815LLU,18446744073709551615LLU,18446744073709551615LLU,9223370387570554943LLU,11492060331937627136LLU,18439986471487103999LLU,18446735002603355139LLU,18446735281829707007LLU,18446744071544741887LLU,1044799868997468097LLU,4194296LLU},{18446744073709551615LLU,18428729675200135167LLU,15852668385302151167LLU,18446744038246694887LLU,18442381069030719487LLU,18444493373407297533LLU,18358923051912919036LLU,18446744073709551615LLU,18446744073709551615LLU,18446690992208740351LLU,14411307665900438527LLU,18428738471293091838LLU,18228319225192120051LLU,18445894769696571391LLU,4193287LLU},{18446744073709551615LLU,18014398509481983LLU,18445899228937977856LLU,9223204910852472223LLU,17154210980654219260LLU,13837309855095848767LLU,18446744073707388851LLU,18446744072098351103LLU,18446725931128062975LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU,18446665183750160335LLU,18446744073709533247LLU,4129791LLU},{18446741856944390129LLU,9150152395927584767LLU,18446744073705226215LLU,18446743523953737729LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17292120525098835967LLU,18446462736171659263LLU,18104470003811352444LLU,18446744005258375165LLU,9148957086128531455LLU,18446744073709549568LLU,17582044973392334591LLU,3963623LLU},{9187290154039758735LLU,17149707381026844540LLU,18446744073709534623LLU,549755813887LLU,9493588014496997376LLU,18149506360661245951LLU,14411230735505571839LLU,18446744073709551615LLU,18446744073709551615LLU,13258171240075493375LLU,18372980106344791535LLU,17149706229975613383LLU,16716815359516084223LLU,14981162553437061119LLU,3397629LLU},{18445407067469462655LLU,18446736377108234211LLU,18446744073709551615LLU,18446744073709551615LLU,9222738718157185023LLU,18446598933074409968LLU,18446744005023629311LLU,18403959864234606335LLU,17870564796382838717LLU,18446744073709551615LLU,18446744073709551615LLU,18446321655086055423LLU,18429292586502979583LLU,4611686018423324663LLU,1048479LLU},{18446744073690742771LLU,18446743506672615455LLU,18446586293690302463LLU,13690093494742286335LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU,18229445271426693600LLU,18446497779866926207LLU,18446744073709551615LLU,18446744073709551615LLU,18446665183750258687LLU,18014398509463615LLU,18446744073709453263LLU,3997672LLU},{17287031981128802207LLU,18428738471293091837LLU,18411841107072647167LLU,18446744073692247023LLU,11525837346347933699LLU,18444773722968541183LLU,18446744073680191101LLU,18446744073709551615LLU,576460752303423487LLU,18446744073441116160LLU,18446744073709551615LLU,18429292590793752575LLU,18446321655081992183LLU,16140901060205084671LLU,3406975LLU}};

static uint_fast64_t D[18][15] = {{18446744073709551615LLU,18446744073709551615LLU,7978081642721837055LLU,18389814234419353339LLU,13258513136641353527LLU,9223372036832717782LLU,5440255800204548831LLU,18446559037582213069LLU,16847185198129872895LLU,18337240274300157909LLU,9199689504967360511LLU,18446744070186250059LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{17991307517336877054LLU,13208617895639988671LLU,18446744073707906814LLU,18446744073709551615LLU,18219030817550630911LLU,10261959087490719359LLU,18413915405283229695LLU,13096112502196824946LLU,4611686018423665894LLU,15983169480289142191LLU,10042604956570826550LLU,18446744073678977535LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446737389054327485LLU,8859031050439622655LLU,17712024004452810549LLU,16631738448297852924LLU,18446687996917676236LLU,18446744073709551615LLU,18446744073709551615LLU,5750511234025627583LLU,16011422386020208639LLU,16985319311119383162LLU,18446712462342148089LLU,18446744072968460031LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{3926698211419581927LLU,14843864371813074535LLU,11240960166926948811LLU,18446743400265498423LLU,18104329270181953535LLU,17410914645905440745LLU,13039317010691893222LLU,18446744073709551615LLU,18446744073709551615LLU,4034503155419971583LLU,17651225297248319695LLU,18446744073709551540LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{14975489103317868379LLU,18428718903235968984LLU,18409166407028703231LLU,1871936138145950159LLU,5758415073546592251LLU,18443986450899776959LLU,18446744004948983097LLU,18047049447323989247LLU,17869938618554907417LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446739675663040512LLU,18446744073709551615LLU,18446744073709551615LLU,17365880145956831231LLU,18446726412753698559LLU,18446742974231478271LLU,18444633009235689471LLU,9223653511831486459LLU,18428720879107047423LLU,144115188042300479LLU,17906307703198711804LLU,18446744073707585535LLU,12635657989632289661LLU,17847604788923654142LLU,4194303LLU},{9799832789158199295LLU,18446180994907109375LLU,6283257LLU,18446744073709551614LLU,18446744073709551615LLU,9079186480034742271LLU,17906312118425075712LLU,18446744073709551599LLU,18446743936274726879LLU,18446744073575088127LLU,9223372036586798847LLU,13212412857716572152LLU,8791012574113038335LLU,18228881735112717147LLU,4194303LLU},{18158522493650862079LLU,18442240199204274175LLU,18446744073709547759LLU,16140901064495726595LLU,70336397703167LLU,18446744073692774400LLU,18446744073709551615LLU,18446744073709551615LLU,18302624762464567280LLU,18446744073696442367LLU,18428764851519094663LLU,8856012002502377471LLU,18446744071476535294LLU,18122377963753696509LLU,4194303LLU},{18446744073709551615LLU,18446744069414699006LLU,18446744073708568511LLU,18410716238754873343LLU,18446735826835472383LLU,17293789583753871359LLU,8065946915440197631LLU,18446603336221196318LLU,18446744073709551615LLU,18446744073709551615LLU,17293820507518371839LLU,14843852122566361199LLU,15485606418563724507LLU,18435190302445666303LLU,4194303LLU},{18446744073709551615LLU,35762715205041207LLU,18446744073709551615LLU,18446744065589379071LLU,18446744073701179270LLU,18378627129345572863LLU,18446673841389305855LLU,18446744073709551615LLU,1144406886561318655LLU,18374686479940059104LLU,18446744073709551615LLU,18427955241056993279LLU,18427955241052618663LLU,18446744073705176999LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,14969964628803583999LLU,18428518568699232255LLU,18446739435144081343LLU,13835058055298940927LLU,18446744073709551615LLU,18446700091297497087LLU,18153979242080108543LLU,18410653291671060469LLU,13853071294125309951LLU,18446744071293612031LLU,18446735281506746305LLU,17869291560573575167LLU,4155575LLU},{18446744073709551615LLU,18446744073709551615LLU,9222272525226999807LLU,36028517846023422LLU,16717300226961965052LLU,18446744073704308503LLU,15852648663211302815LLU,140737488355321LLU,18446744073707454464LLU,18438578000850059263LLU,18441099176516255743LLU,18446744073692839899LLU,12673023795082955775LLU,7939793366496049152LLU,4167673LLU},{18446744073709551615LLU,18446744073709551615LLU,17935582217468116991LLU,18439425664185505791LLU,13835058054216809599LLU,18446744073709317116LLU,18428800036411011839LLU,18446742106587267071LLU,18383550714497466367LLU,72057594037919775LLU,18446744073709289472LLU,18446744073709551615LLU,18190883319820058239LLU,11529214500548050943LLU,4194126LLU},{288229961687304191LLU,16708213877883535328LLU,18446744073708998655LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU,18446744004990074880LLU,13780943376465493631LLU,13835058055281098639LLU,11524218861809298927LLU,4611686018427370623LLU,16708354351247097280LLU,18428738471293091839LLU,1072982557500374003LLU,2613247LLU},{18300936737107476479LLU,4611677226629299711LLU,18446744073702209535LLU,18446744073709551615LLU,18373842054741491711LLU,16104625420665485567LLU,18436575240420065279LLU,18446744073709551591LLU,17870283321408225279LLU,18383658468784472063LLU,15843522751600820156LLU,4611136258335309823LLU,9079252399192801279LLU,17437374394904086527LLU,1933191LLU},{18388197217618493439LLU,18444773748000154623LLU,18446744073709551488LLU,18446744073709551615LLU,18417470676131643391LLU,17941197200011026303LLU,13853072453791645695LLU,16573231165767404543LLU,18446744073709321719LLU,18446744073707462655LLU,18446726481523769343LLU,18191163145588834303LLU,16429129653941174271LLU,18446674254251425375LLU,3863293LLU},{18446743589384879807LLU,18430977005024444415LLU,14383934257183555711LLU,17843244131455860735LLU,18446743799905379325LLU,18446744073709551615LLU,18446744073709551615LLU,11524588301038075903LLU,17942340812295897087LLU,18446744073443213311LLU,17592186044415LLU,16415339166788747200LLU,18446744073236578303LLU,18437807239437744639LLU,2608575LLU},{13618740687387721207LLU,18446744073709494255LLU,4611672545039515647LLU,18446743592536801214LLU,18338587588786388991LLU,14411517982400315379LLU,4611685958297833463LLU,18446744073709551584LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,2305836270410006591LLU,2292325609503717855LLU,8079457731502669823LLU,1916923LLU}};

uint_fast8_t X[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[18][15] = {{18446744073709551615LLU,18446744073709551615LLU,7978081642721837055LLU,18389814234419353339LLU,13258513136641353527LLU,9223372036832717782LLU,5440255800204548831LLU,18446559037582213069LLU,16847185198129872895LLU,18337240274300157909LLU,9199689504967360511LLU,18446744070186250059LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[18];
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
            "popcnt %2, %2  \n\t"
            "add %2, %0     \n\t"
            "popcnt %3, %3  \n\t"
            "add %3, %1     \n\t"
            : "+r" (cnt[16]), "+r" (cnt[17])
            : "r" (buf[16]), "r" (buf[17]));


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14] + cnt[15] + cnt[16] + cnt[17];
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
        A[i][14] = A[i-1][14] & C[i][14];

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
        A[i][14] = A[i-1][14] & D[i][14];

    }
}

void printout(){
    sprintf(str, "[                  ,%5d]\n", this);
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
    fputs("[[0,2],[0,3],[0,4],[0,5],[0,6],[1,2],[1,3],[1,4],[1,5],[1,6],[2,4],[2,5],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]]\n", fout);
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
