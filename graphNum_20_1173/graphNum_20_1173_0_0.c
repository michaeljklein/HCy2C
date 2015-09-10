#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_20_1173_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 19;
static uint_fast32_t endhere = 0;
char str[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[20][16] = {{18446603336221196035LLU,18428729675202166783LLU,18446739675650457599LLU,18446708897927396864LLU,18446744073709551615LLU,18446744073696968703LLU,18446744073709551615LLU,17179869183LLU,18410715276690587648LLU,18446744072636858367LLU,18438299824408231935LLU,2305842184579973119LLU,18446739675663040504LLU,18446462598732873727LLU,18446198681582338047LLU,18014397436788735LLU},{18446744073709551615LLU,18446744073709551615LLU,2251799813685247LLU,0LLU,0LLU,18445618173802708992LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU,0LLU,0LLU,18410715276690587648LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,36028797018963967LLU,0LLU,0LLU,17293822569102704640LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18302628885633695744LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,2251799813685247LLU,17275525596104884160LLU,13753984457271801595LLU,71912454191308799LLU,17861240937779296256LLU,15852389135923208061LLU,1148277030035128311LLU,18442240474082181120LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{144115188075855871LLU,18428729675200069632LLU,4503599627370495LLU,7926194606683717120LLU,18446739123457226495LLU,18446735140110430206LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,13761874555968686079LLU,18410713076576812015LLU,18302624483155868670LLU,4503599627370495LLU,18446462598732840960LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18014398509481983LLU,18444492273895866368LLU,18428729669831361023LLU,18302628816909959131LLU,18446109650666126775LLU,9076969864425373759LLU,17869157351706050527LLU,18442240336506846175LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU,18446726481523507200LLU,18014398509481983LLU},{18446744073172680705LLU,16212817921032847359LLU,18445600302443790335LLU,1073741823LLU,18446742974197923840LLU,9227875636482146303LLU,18446744073709551615LLU,18446742012125249535LLU,144114363442135039LLU,18446735286206463999LLU,18446744073709551615LLU,288203987067332607LLU,18446744073692774400LLU,18429290426130038783LLU,17870291977879158783LLU,18014398509481983LLU},{432345564764438527LLU,18437727494246236159LLU,18446742974196350975LLU,18446744073709551615LLU,1099511627775LLU,9222246136947933184LLU,18446743799100080064LLU,18446744073709551615LLU,18419722475139628863LLU,18446744073709549568LLU,18446678103011885055LLU,18446744047939747839LLU,18163017297201987583LLU,18446603189655437311LLU,576460743713476607LLU,18014398509480960LLU},{285978164021166079LLU,13835058055280066560LLU,8655353923106815LLU,18446744073709551615LLU,14123288431433875455LLU,18446744047939747839LLU,33554431LLU,18446744056529682432LLU,18446744073709551615LLU,18446532967475974143LLU,18446743661389545471LLU,18418878051015196431LLU,4433217998290943LLU,18410715276690554880LLU,8070447783456275439LLU,18014398508433854LLU},{0LLU,0LLU,18444492273895866368LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073642441215LLU,33741799947960317LLU,18446744073709289472LLU,18442521949056795647LLU,18446744060824649727LLU,18446744073709551615LLU,18446737476639752319LLU,9223372036647157759LLU,18445899623009615864LLU,1073741823LLU,18446743523953737728LLU,18446744073709551615LLU,17870283321404030927LLU,245740647476223LLU,18229691682293544960LLU,18014330846704639LLU},{18446744006063292415LLU,18446181123655467007LLU,18444492273896128511LLU,18446744072637906943LLU,18410724072783597567LLU,18446744073709551615LLU,18446744073676029951LLU,18446480190918885375LLU,18446717685430484991LLU,18446744073709551615LLU,549755813887LLU,17293822569102704640LLU,18446744071595606015LLU,18446735277614956543LLU,576443160117381119LLU,18010068910833663LLU},{18443638915433496831LLU,18014204995162864640LLU,18167520896812580351LLU,35184372023229LLU,17582052945254415872LLU,18307132458434290687LLU,274877906933LLU,18430981062696894456LLU,16429130582727852031LLU,18446743558313353151LLU,18446744073709436927LLU,18446744073709551615LLU,288133339955585031LLU,18443363350327787504LLU,18429292625153490939LLU,17983601446454271LLU},{18446743796147552255LLU,16717361610630366207LLU,288230374826311679LLU,18446744073696968687LLU,14987872907261116927LLU,9367487224930631679LLU,18446744073709355007LLU,18446742407262240775LLU,2305843009213677823LLU,18446735827354648575LLU,9007199254740991LLU,18446744073709551422LLU,18446744065035739135LLU,18433233271606050831LLU,17888297719905255423LLU,17767901745414143LLU},{14987909259794021887LLU,2305843009213689855LLU,17870176668744155008LLU,18445899648506758143LLU,36028784133029880LLU,18158513697557315584LLU,18446744057603420408LLU,18446744073709548031LLU,15564440312192434175LLU,8796093022176LLU,17942327721304522496LLU,18445653332404994047LLU,18392698681303137263LLU,18014398509481919LLU,18446743240485629951LLU,17134781690731488LLU},{4467641199095708663LLU,18446744063106351103LLU,18446744047938437247LLU,18443366270874189817LLU,18446744073709551615LLU,18445618173803233279LLU,18446743816010960839LLU,17294104044079415295LLU,18446744073709551609LLU,18446744073703258143LLU,18446690747395604735LLU,13835058055281647615LLU,18226069890991652831LLU,18446744073543876607LLU,18446744073508214784LLU,14632240583537695LLU},{12668481165995278287LLU,9223367640955645951LLU,15564440312192421880LLU,18446742012124981191LLU,4611686017956708351LLU,17005590028274892672LLU,18446744018948709614LLU,1152921504598716927LLU,18446744073675997184LLU,17294104043953585913LLU,18446744073445310463LLU,9223372036854775807LLU,18356245350390890494LLU,17365880094454708671LLU,18374580926555357087LLU,13123752418082681LLU},{16140835085208248127LLU,18428734073246580687LLU,18410714761286123399LLU,16429098455231602239LLU,18445055223849287679LLU,18428729675199545471LLU,18411278213755958265LLU,18446744073709551615LLU,18410715276724142079LLU,1152921503667306471LLU,18439988674268495616LLU,18446744072636334079LLU,4575655159555686137LLU,1152640098349613055LLU,16138227048190509055LLU,8434896070508519LLU},{18446741823146442719LLU,18158509574322125887LLU,18228320041537896441LLU,2305841359006724063LLU,18412967076504272384LLU,18338657682652659599LLU,36028796989603327LLU,18446532967477018616LLU,16717361816765743103LLU,17311836555194564603LLU,18446744073709551615LLU,17293822570176446463LLU,18446744003379454462LLU,17579801081015173104LLU,4598087262910021631LLU,13208433115242491LLU}};

static uint_fast64_t D[20][16] = {{18370745307951952383LLU,9367487224930631679LLU,18446215206635106815LLU,18410996750831385599LLU,13843537355804118976LLU,18445758877065543679LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU,18446462633092578110LLU,13907049146042302463LLU,18410750435292872449LLU,18444369112279626639LLU,18375812379578466303LLU,8070446400473909731LLU,18014398508433854LLU},{18158513697557839870LLU,4568227446365805225LLU,18445815351829178197LLU,18446744073709551615LLU,18446744073709551615LLU,18444492273895866367LLU,14933079844735418495LLU,4386127778916722419LLU,18373125125864660725LLU,16689953188794601471LLU,11228880481005526649LLU,18396780752390053543LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18183733059191730685LLU,13907115649320091647LLU,18440917396148869290LLU,7920283630025311231LLU,18398703637987043062LLU,18446576534349573996LLU,18446744073709551615LLU,18446744073709551615LLU,144115188075855871LLU,4392123807037386752LLU,17762102351897670607LLU,18013224183409832956LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{551241390669532675LLU,18418145051733206358LLU,9007199254740991LLU,15798580578887924736LLU,12249789680160931227LLU,3866934590036407LLU,8784165153521270656LLU,16695966760401845662LLU,18433196577143976863LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,2251799813685247LLU,18446744072635809792LLU,18446744073709551615LLU,18446744073709551615LLU,4392078361787105279LLU,17580188068705443791LLU,18439407908586158538LLU,11419299061220507647LLU,9163695766741449191LLU,18211986789660309854LLU,12101172198744522751LLU,12285422218254961514LLU,18446736818069861198LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18416907719735771135LLU,18206557845969592265LLU,174265341705363LLU,18446744073675997184LLU,18446744073709551615LLU,18446744073709551615LLU,17568483511478779903LLU,14555167686564925244LLU,16710377495038914547LLU,18443028579133240207LLU,6161487240196259839LLU,18446733737163197617LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,2665896422649364479LLU,6341060849959170687LLU,18446730656122611710LLU,16689916174229569535LLU,11407603274663391865LLU,17796138446606207LLU,18446744072635809792LLU,18446744073709551615LLU,2305843009213693951LLU,6349287369541340272LLU,18446578688967881877LLU,18446744073709551615LLU,18014398509481983LLU},{288230376151711743LLU,4597598189380435967LLU,18446390537232688981LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446743798859366655LLU,17435703549550919679LLU,18411814787277668097LLU,10248011320106414079LLU,18446673840492771555LLU,18418878017725472719LLU,18163017297185210367LLU,12285599661137854463LLU,576457990299697998LLU,18014398509480960LLU},{18446744073709551615LLU,16174430598554901161LLU,18445024017527078911LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,2049632610658353023LLU,9223369852924694471LLU,18445898557854054654LLU,18446735278335860735LLU,4540191374342881279LLU,17329816455587291198LLU,12105675798371893247LLU,18428972099193031530LLU,17870287475653246975LLU,18014398509481983LLU},{18401454063406284545LLU,18374686479671623679LLU,18445593619459956394LLU,18446708890173376511LLU,18438273436129165311LLU,18446619004245179393LLU,18446744073709551615LLU,18446744073709551615LLU,18302628885633695743LLU,8198803095858183361LLU,18437807227931707164LLU,288202921885624319LLU,18445328760887574520LLU,6196390137308381183LLU,18446189728018349757LLU,18014397436788735LLU},{18446744073709551615LLU,18446744073709551615LLU,18444492273895866367LLU,13174623938505867263LLU,6244994829271128941LLU,18445296478293178075LLU,13176243149162414079LLU,15811393608100535149LLU,18389795330044161386LLU,15811411151587115007LLU,7902505314515905974LLU,17777305780721921371LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{17870283252945751963LLU,18436880732735386967LLU,7512004178453987327LLU,36020524911951694LLU,18410715414070804543LLU,3756002089226993663LLU,16397113661241425919LLU,18446464782723481144LLU,18419688390249793343LLU,18446744073709551615LLU,18446744073709551615LLU,16140901064495857663LLU,6908521826246954108LLU,18446589959006830293LLU,576460752303423487LLU,18010068910833663LLU},{1127702143719962727LLU,18443172844091764732LLU,10943747094510305279LLU,18442248754779127473LLU,288230359038033919LLU,14695229924529079294LLU,18446735278690271168LLU,1011056054492197375LLU,18445652500255080440LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU,17311048862584471491LLU,18446688273246773695LLU,18229691682293547007LLU,18014330846704639LLU},{18401671790330904575LLU,9209298029213908991LLU,18446744073441316766LLU,18446744073694066671LLU,18446612132314218495LLU,18446619004261433329LLU,18446744073709295359LLU,17437884980620427263LLU,18411814788318347271LLU,18429011149610548461LLU,532580138755LLU,18446744073709551614LLU,18445335564853968895LLU,4395293329944215551LLU,17870283321404032543LLU,17767900898131565LLU},{18445673123614294015LLU,18446677269318467583LLU,18446735698523323489LLU,18446744073474559933LLU,18438299824408231935LLU,18446744072636325903LLU,18446744073703778805LLU,18428800043944247295LLU,18446744039382859769LLU,18014398339612563LLU,18446744073709420796LLU,18446742975238119423LLU,18446710606519074815LLU,14123287387615264767LLU,11529214980637327352LLU,17983601222090707LLU},{18446744073432592371LLU,18446744071562566899LLU,7906627665405149183LLU,18194542365694230520LLU,18446743111578156607LLU,13177532509686071295LLU,2305288855335600127LLU,17293822569370882040LLU,18446744073709551615LLU,18446744073701351423LLU,4609997168567123967LLU,10412321513846341886LLU,14987979559880355711LLU,18446744073676004979LLU,18112320980439236607LLU,14629689386598399LLU},{18446744073705562015LLU,18445685037853565711LLU,17473834199352868863LLU,288222129541873487LLU,18446744073708503544LLU,17960355313953538047LLU,16141464014438727679LLU,18446744073709547527LLU,15564405162147037439LLU,18446744073357049855LLU,17872535121219813375LLU,18445619272274149183LLU,4611686018427263228LLU,18446727526274301836LLU,18421762135504257023LLU,17133070951800831LLU},{18374123516430108671LLU,17149707381025275843LLU,9169328291838754303LLU,16145404664004673535LLU,18444631929052450815LLU,13807051294159929343LLU,18410724072779677695LLU,18446744056798117887LLU,8935141660703064063LLU,18446737373560019903LLU,18446743541133492223LLU,18446744072635809793LLU,1150652112191864383LLU,18436610974547943423LLU,14696371479723899387LLU,6741380667239935LLU},{13818169520142744575LLU,17582052945254292735LLU,14841753309285434367LLU,18443366373443371007LLU,18419616922293239303LLU,16645302024811839487LLU,2305842957657169903LLU,18446744073701167096LLU,12682136550675316735LLU,18446742012124921471LLU,576407975476985855LLU,17294948469009547262LLU,18374158712948516831LLU,18439988674268493939LLU,9106261953867145095LLU,12312176588863295LLU},{6791375186135351159LLU,17276934068879097855LLU,4611686018427142047LLU,18446717582349680379LLU,14987978460914253823LLU,11528091345184366591LLU,18446743854666201051LLU,17311835301173264383LLU,9187378424207900671LLU,18446737476098193903LLU,18446743524222172931LLU,13835058055282163711LLU,18262657781067677691LLU,4602414936356653055LLU,18014117034505271423LLU,6614622751948015LLU}};

uint_fast8_t X[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[20][16] = {{18370745307951952383LLU,9367487224930631679LLU,18446215206635106815LLU,18410996750831385599LLU,13843537355804118976LLU,18445758877065543679LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU,18446462633092578110LLU,13907049146042302463LLU,18410750435292872449LLU,18444369112279626639LLU,18375812379578466303LLU,8070446400473909731LLU,18014398508433854LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[20];
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


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14] + cnt[15] + cnt[16] + cnt[17] + cnt[18] + cnt[19];
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
        A[i][15] = A[i-1][15] & C[i][15];

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
        A[i][15] = A[i-1][15] & D[i][15];

    }
}

void printout(){
    sprintf(str, "[                    ,%5d]\n", this);
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
    fputs("[[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,5],[2,6],[3,5],[3,7],[4,6],[4,8],[5,8],[5,9],[6,7],[6,9],[7,8],[7,9],[8,9]]\n", fout);
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

