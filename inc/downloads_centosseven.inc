###############################################
atrpmssevenyum() {

if [[ "$ATRPMSREPO_DISABLE" = [nN] ]]; then

# if [ ${MACHINE_TYPE} == 'x86_64' ]; then
    cd $DIR_TMP

  if [ -s "${CENTOSSEVENATRPMSFILE}" ]; then
    echo "${CENTOSSEVENATRPMSFILE} [found]"
    rpm --import http://packages.atrpms.net/RPM-GPG-KEY.atrpms
    rpm -ivh ${CENTOSSEVENATRPMSFILE}
    sed -i 's|enabled=1|enabled=0|g' /etc/yum.repos.d/atrpms.repo
    ERR=$?
    CCATRPMSCHECK="$ERR"
      if [ "$CCATRPMSCHECK" == '0' ]; then
        yumprioratrpms
        echo ""
      else
        cecho "Error: problem with ${CENTOSSEVENATRPMSFILE} install." $boldgreen
        exit $ERR
      fi    
    else
    echo "Error: ${CENTOSSEVENATRPMSFILE} not found !!! Downloading now......"
    wget ${WGETOPT} ${CENTOSSEVENATRPMS} --tries=3
    # wget ${WGETOPT} ${CENTOSSEVENATRPMSLOCAL} --tries=3
  ERROR=$?
    if [[ "$ERROR" != '0' ]]; then
    cecho "Error: ${CENTOSSEVENATRPMSFILE} download failed." $boldgreen
  FAILATRPMS='y'
  checklogdetails
    # exit #$ERROR
  else 
    cecho "Download done." $boldyellow
    rpm --import http://packages.atrpms.net/RPM-GPG-KEY.atrpms
    rpm -ivh ${CENTOSSEVENATRPMSFILE}
    sed -i 's|enabled=1|enabled=0|g' /etc/yum.repos.d/atrpms.repo
    ERR=$?
    CCATRPMSCHECK="$ERR"
      if [ "$CCATRPMSCHECK" == '0' ]; then
        yumprioratrpms
        echo ""
      else
        cecho "Error: problem with ${CENTOSSEVENATRPMSFILE} install." $boldgreen
        exit $ERR
      fi
    fi
  
  fi

# fi # MACHINE_TYPE

fi # ATRPMSREPO_DISABLE

}

###############################################
axivoseven() {

if [[ "$AXIVOREPO_DISABLE" = [nN] ]]; then

if [ ${MACHINE_TYPE} == 'x86_64' ]; then

    cd $DIR_TMP  

if [ -s "${CENTOSSEVENAXIVOFILE}" ]; then
  echo "${CENTOSSEVENAXIVOFILE} [found]"
  else
  echo "Error: ${CENTOSSEVENAXIVOFILE} not found !!! Downloading now......"
  wget ${WGETOPT} ${CENTOSSEVENAXIVO} --tries=3
  # wget ${WGETOPT} ${CENTOSSEVENAXIVOLOCAL} --tries=3
ERROR=$?
  if [[ "$ERROR" != '0' ]]; then
  cecho "Error: ${CENTOSSEVENAXIVOFILE} download failed." $boldgreen
FAILAXIVO='y'
checklogdetails
  # exit #$ERROR
else 
  cecho "Download done." $boldyellow
  rpm -ivh --nosignature ${CENTOSSEVENAXIVOFILE}
  ERR=$?
  CCAXIVOCHECK="$ERR"
    if [ "$CCAXIVOCHECK" == '0' ]; then
      yumprioraxivo
      echo ""
    else
      cecho "Error: problem with ${CENTOSSEVENAXIVOFILE} install." $boldgreen
      exit $ERR
    fi
  fi

fi

fi

fi # AXIVOREPO_DISABLE

}

###############################################

remisevenyum() {

if [[ "$REMIREPO_DISABLE" = [nN] ]]; then

# if [ ${MACHINE_TYPE} == 'x86_64' ]; then
    cd $DIR_TMP

  if [ -s "${CENTOSSEVENREMIFILE}" ]; then
    echo "${CENTOSSEVENREMIFILE} [found]"
    rpm -ivh --nosignature ${CENTOSSEVENREMIFILE}
    ERR=$?
    CCREMICHECK="$ERR"
      if [ "$CCREMICHECK" == '0' ]; then
        yumpriorremi
        echo ""
      else
        cecho "Error: problem with ${CENTOSSEVENREMIFILE} install." $boldgreen
        exit $ERR
      fi    
    else
    echo "Error: ${CENTOSSEVENREMIFILE} not found !!! Downloading now......"
    wget ${WGETOPT} ${CENTOSSEVENREMI} --tries=3
    # wget ${WGETOPT} ${CENTOSSEVENREMILOCAL} --tries=3
  ERROR=$?
    if [[ "$ERROR" != '0' ]]; then
    cecho "Error: ${CENTOSSEVENREMIFILE} download failed." $boldgreen
  FAILREMI='y'
  checklogdetails
    # exit #$ERROR
  else 
    cecho "Download done." $boldyellow
    rpm -ivh --nosignature ${CENTOSSEVENREMIFILE}
    ERR=$?
    CCREMICHECK="$ERR"
      if [ "$CCREMICHECK" == '0' ]; then
        yumpriorremi
        echo ""
      else
        cecho "Error: problem with ${CENTOSSEVENREMIFILE} install." $boldgreen
        exit $ERR
      fi
    fi
  
  fi

# fi # MACHINE_TYPE

fi # REMIREPO_DISABLE

}

###############################################
yumcentossevendownload() {

if [[ "$CENTOSVER" = '7.0' || "$CENTOSVER" = '7.1' || "$CENTOSVER" = '7.2' || "$CENTOSVER" = '7.3' || "$CENTOSVER" = '7.4' || "$CENTOSVER" = '7.5' || "$CENTOSVER" = '7.6' || "$CENTOSVER" = '7.7' ]]; then
{
echo "*************************************************"
cecho "* CentOS 7.x detected installing EPEL Repo" $boldgreen
echo "*************************************************"

    if [ ${MACHINE_TYPE} == 'x86_64' ];
    then
        ARCH='x86_64'
       RPMFARCH='x86_64'
    else
        ARCH='i686'
        RPMFARCH='i386'
    fi

    cd $DIR_TMP

if [ -f /etc/yum.repos.d/epel.repo ]; then
  yumpriorepel
elif [ ! -f /etc/yum.repos.d/epel.repo ]; then
  if [ -s "${CENTOSSEVENEPELFILE}" ]; then
    echo "${CENTOSSEVENEPELFILE} [found]"
    else
    echo "Error: ${CENTOSSEVENEPELFILE} not found !!! Downloading now......"
    wget ${WGETOPT} ${CENTOSSEVENEPEL} --tries=3
    # wget ${WGETOPT} ${CENTOSSEVENEPELLOCAL} --tries=3
  ERROR=$?
	 if [[ "$ERROR" != '0' ]]; then
	 cecho "Error: ${CENTOSSEVENEPELFILE} download failed." $boldgreen
  FAILEPEL='y'
  checklogdetails
	 # exit #$ERROR
  else 
	 cecho "Download done." $boldyellow
    rpm --import http://epel.mirror.constant.com/RPM-GPG-KEY-EPEL-7
    rpm -i ${CENTOSSEVENEPELFILE}
	 #yum${CACHESKIP} -q list ccache 2>&1 >/dev/null
	 ERR=$?
	 CCEPELCHECK="$ERR"
		  if [ "$CCEPELCHECK" == '0' ]; then
			 yumpriorepel
			 echo ""
		  else
			 cecho "Error: problem with ${CENTOSSEVENEPELFILE} install." $boldgreen
			 exit $ERR
		  fi
	 fi
  fi
fi

if [[ "$RPMFORGEREPO_DISABLE" = [nN] ]]; then
  if [[ -f /etc/yum.repos.d/rpmforge.repo || -f /etc/yum.repos.d/rpmforge.OLD ]]; then
    rm -rf /etc/yum.repos.d/rpmforge.repo
    rm -rf /etc/yum.repos.d/rpmforge.OLD
    # rm -rf ${DIR_TMP}/rpmforge-release*
  
    FORGERPM=$(rpm -qa | grep rpmforge-release)
    rpm -e $FORGERPM
  fi

  cd $DIR_TMP  
  
  if [ -s "${CENTOSSEVENRPMFORGEFILE}" ]; then
    echo "${CENTOSSEVENRPMFORGEFILE} [found]"
  rpm --import http://apt.sw.be/RPM-GPG-KEY.dag.txt
  rpm -i ${CENTOSSEVENRPMFORGEFILE}    
    ERR=$?
    CCRPMFORGECHECK="$ERR"
      if [ "$CCRPMFORGECHECK" == '0' ]; then
        yumpriorrpmforge
        echo ""
      else
        cecho "Error: problem with ${CENTOSSEVENRPMFORGEFILE} install." $boldgreen
        #exit $ERR
      fi  
    else
    echo "Error: ${CENTOSSEVENRPMFORGEFILE} not found !!! Downloading now......"
    wget ${WGETOPT} ${CENTOSSEVENRPMFORGE} --tries=3 
  ERROR=$?
    if [[ "$ERROR" != '0' ]]; then
    cecho "Error: ${CENTOSSEVENRPMFORGEFILE} download failed." $boldgreen
  FAILRPMFORGE='y'
  checklogdetails
    #exit #$ERROR
  else 
          cecho "Download done." $boldyellow
  rpm --import http://apt.sw.be/RPM-GPG-KEY.dag.txt
  rpm -i ${CENTOSSEVENRPMFORGEFILE}
    yum${CACHESKIP} -q list axel 2>&1 >/dev/null
    ERR=$?
    CCRPMFORGECHECK="$ERR"
      if [ "$CCRPMFORGECHECK" == '0' ]; then
        yumpriorrpmforge
        echo ""
      else
        cecho "Error: problem with ${CENTOSSEVENRPMFORGEFILE} install." $boldgreen
        #exit $ERR
      fi
    fi
  
  fi
fi # RPMFORGEREPO_DISABLE = n


if [[ "$CENTALTREPO_DISABLE" = [nN] ]]; then
if [ -s "${CENTOSSEVENCENTALTFILE}" ]; then
  echo "${CENTOSSEVENCENTALTFILE} [found]"
  else
  echo "Error: ${CENTOSSEVENCENTALTFILE} not found !!! Downloading now......"
  wget ${WGETOPT} ${CENTOSSEVENCENTALT} --tries=3
  # wget ${WGETOPT} ${CENTOSSEVENCENTALTLOCAL} --tries=3
ERROR=$?
  if [[ "$ERROR" != '0' ]]; then
  cecho "Error: ${CENTOSSEVENCENTALTFILE} download failed." $boldgreen
FAILCENTALT='y'
checklogdetails
  # exit #$ERROR
else 
         cecho "Download done." $boldyellow
rpm --import http://centos.alt.ru/pub/repository/centos/RPM-GPG-KEY-CentALT
rpm -i ${CENTOSSEVENCENTALTFILE}
yumpriorcentalt
echo ""
  fi

fi
fi # CENTALTREPO_DISABLE

  cd $DIR_TMP

if [ -s "${CENTOSSEVENPERCONALRELEASEFILE}" ]; then
  echo "${CENTOSSEVENPERCONALRELEASEFILE} [found]"
  rpm --import http://www.percona.com/downloads/RPM-GPG-KEY-percona
  rpm -i ${CENTOSSEVENPERCONALRELEASEFILE}  
  ERR=$?
  CCPERCONACHECK="$ERR"
    if [ "$CCPERCONACHECK" == '0' ]; then
      yumpriorpercona
      echo ""
    else
      cecho "Error: problem with ${CENTOSSEVENPERCONALRELEASEFILE} install." $boldgreen
      exit $ERR
    fi  
  else
  echo "Error: ${CENTOSSEVENPERCONALRELEASEFILE} not found !!! Downloading now......"
  wget ${WGETOPT} ${CENTOSSEVENPERCONALRELEASE} --tries=3 
ERROR=$?
  if [[ "$ERROR" != '0' ]]; then
  cecho "Error: ${CENTOSSEVENPERCONALRELEASEFILE} download failed." $boldgreen
FAILPERCONA='y'
checklogdetails
  # exit #$ERROR
else 
         cecho "Download done." $boldyellow
rpm --import http://www.percona.com/downloads/RPM-GPG-KEY-percona
rpm -i ${CENTOSSEVENPERCONALRELEASEFILE}
  #yum -q list axel 2>&1 >/dev/null
  ERR=$?
  CCPERCONACHECK="$ERR"
    if [ "$CCPERCONACHECK" == '0' ]; then
      yumpriorpercona
      echo ""
    else
      cecho "Error: problem with ${CENTOSSEVENPERCONALRELEASEFILE} install." $boldgreen
      exit $ERR
    fi
  fi

fi

    cd $DIR_TMP

if [ -s "${CENTOSSEVENVARNISHFILE}" ]; then
  echo "${CENTOSSEVENVARNISHFILE} [found]"
  rpm --nosignature -i ${CENTOSSEVENVARNISHFILE}
  ERR=$?
  CCVARNISHCHECK="$ERR"
    if [ "$CCVARNISHCHECK" == '0' ]; then
      yumpriorvarnish
      echo ""
    else
      cecho "Error: problem with ${CENTOSSEVENVARNISHFILE} install." $boldgreen
      exit $ERR
    fi  
  else
  echo "Error: ${CENTOSSEVENVARNISHFILE} not found !!! Downloading now......"
  wget ${WGETOPT} ${CENTOSSEVENVARNISH} --tries=3
  # wget ${WGETOPT} ${CENTOSSEVENVARNISHLOCAL} --tries=3
ERROR=$?
  if [[ "$ERROR" != '0' ]]; then
  cecho "Error: ${CENTOSSEVENVARNISHFILE} download failed." $boldgreen
FAILVARNISH='y'
checklogdetails
  # exit #$ERROR
else 
         cecho "Download done." $boldyellow

rpm --nosignature -i ${CENTOSSEVENVARNISHFILE}
  #yum -q list axel 2>&1 >/dev/null
  ERR=$?
  CCVARNISHCHECK="$ERR"
    if [ "$CCVARNISHCHECK" == '0' ]; then
      yumpriorvarnish
      echo ""
    else
      cecho "Error: problem with ${CENTOSSEVENVARNISHFILE} install." $boldgreen
      exit $ERR
    fi
  fi

fi

####
# axivo centos 6.x 64bit only
# axivoseven
####
remisevenyum
atrpmssevenyum

# CentOS 7 repo mirrors aren't fully updated so need to specify actual kernel-headers version
PACKAGEEXTRA='clang clang-devel jemalloc jemalloc-devel pngquant optipng jpegoptim pwgen aria2 pigz pbzip2 xz pxz lz4 uw-imap-devel libtidy libtidy-devel libJudy axel glances bash-completion mlocate re2c libmcrypt libmcrypt-devel kernel-headers kernel-devel cmake28'

declare -a arrays
arrays=(${PACKAGEEXTRA})

# if curl one liner is used and detected should skip this yum install routine
# since it's already done by curl installer script
if [ ! -f /usr/local/src/curlinstall_yum.txt ]; then

for pkgs in ${arrays[@]}
do
echo Processing package: $pkgs
YUMINSTALLRPMCHECKS=$(rpm -qa $pkgs)
#echo $YUMINSTALLRPMCHECKS
        if [ "$YUMINSTALLRPMCHECKS" ]; then
echo "----------------------------------------------------------------------------------"
        # yum${CACHESKIP} -q -y update $pkgs
        # yum${CACHESKIP} -q list $pkgs
        echo "$pkg already installed"
echo "----------------------------------------------------------------------------------"
        else
echo "----------------------------------------------------------------------------------"
cecho "Installing $pkgs" $boldyellow
echo "----------------------------------------------------------------------------------"
        yum${CACHESKIP} -q -y install $pkgs
        # yum${CACHESKIP} -q list $pkgs
echo "----------------------------------------------------------------------------------"
        fi
done

fi # /usr/local/src/curlinstall_yum.txt

} 2>&1 | tee ${CENTMINLOGDIR}/centminmod_${SCRIPT_VERSION}_${DT}_yuminstall_centos7.log

fi # CENTOSVER = 7

}
