###############################################
atrpmssixyum() {

if [[ "$ATRPMSREPO_DISABLE" = [nN] ]]; then

# if [ ${MACHINE_TYPE} == 'x86_64' ]; then
    cd $DIR_TMP

  if [ -s "${CENTOSSIXATRPMSFILE}" ]; then
    echo "${CENTOSSIXATRPMSFILE} [found]"
    rpm --import http://packages.atrpms.net/RPM-GPG-KEY.atrpms
    rpm -ivh ${CENTOSSIXATRPMSFILE}
    sed -i 's|enabled=1|enabled=0|g' /etc/yum.repos.d/atrpms.repo
    ERR=$?
    CCATRPMSCHECK="$ERR"
      if [ "$CCATRPMSCHECK" == '0' ]; then
        yumprioratrpms
        echo ""
      else
        cecho "Error: problem with ${CENTOSSIXATRPMSFILE} install." $boldgreen
        exit $ERR
      fi    
    else
    echo "Error: ${CENTOSSIXATRPMSFILE} not found !!! Downloading now......"
    wget ${WGETOPT} ${CENTOSSIXATRPMS} --tries=3
    # wget ${WGETOPT} ${CENTOSSIXATRPMSLOCAL} --tries=3
  ERROR=$?
    if [[ "$ERROR" != '0' ]]; then
    cecho "Error: ${CENTOSSIXATRPMSFILE} download failed." $boldgreen
  FAILATRPMS='y'
  checklogdetails
    # exit #$ERROR
  else 
    cecho "Download done." $boldyellow
    rpm --import http://packages.atrpms.net/RPM-GPG-KEY.atrpms
    rpm -ivh ${CENTOSSIXATRPMSFILE}
    sed -i 's|enabled=1|enabled=0|g' /etc/yum.repos.d/atrpms.repo
    ERR=$?
    CCATRPMSCHECK="$ERR"
      if [ "$CCATRPMSCHECK" == '0' ]; then
        yumprioratrpms
        echo ""
      else
        cecho "Error: problem with ${CENTOSSIXATRPMSFILE} install." $boldgreen
        exit $ERR
      fi
    fi
  
  fi

# fi # MACHINE_TYPE

fi # ATRPMSREPO_DISABLE

}

###############################################
axivosixyum() {

if [[ "$AXIVOREPO_DISABLE" = [nN] ]]; then

if [ ${MACHINE_TYPE} == 'x86_64' ]; then

    cd $DIR_TMP	

if [ -s "${CENTOSSIXAXIVOFILE}" ]; then
  echo "${CENTOSSIXAXIVOFILE} [found]"
  else
  echo "Error: ${CENTOSSIXAXIVOFILE} not found !!! Downloading now......"
  wget ${WGETOPT} ${CENTOSSIXAXIVO} --tries=3
  # wget ${WGETOPT} ${CENTOSSIXAXIVOLOCAL} --tries=3
ERROR=$?
	if [[ "$ERROR" != '0' ]]; then
	cecho "Error: ${CENTOSSIXAXIVOFILE} download failed." $boldgreen
FAILAXIVO='y'
checklogdetails
	# exit #$ERROR
else 
	cecho "Download done." $boldyellow
	rpm -ivh --nosignature ${CENTOSSIXAXIVOFILE}
	ERR=$?
	CCAXIVOCHECK="$ERR"
		if [ "$CCAXIVOCHECK" == '0' ]; then
			yumprioraxivo
			echo ""
		else
			cecho "Error: problem with ${CENTOSSIXAXIVOFILE} install." $boldgreen
			exit $ERR
		fi
	fi

fi

fi

fi # AXIVOREPO_DISABLE

}

###############################################

remisixyum() {

if [[ "$REMIREPO_DISABLE" = [nN] ]]; then

# if [ ${MACHINE_TYPE} == 'x86_64' ]; then
    cd $DIR_TMP

	if [ -s "${CENTOSSIXREMIFILE}" ]; then
  	echo "${CENTOSSIXREMIFILE} [found]"
  	rpm -ivh --nosignature ${CENTOSSIXREMIFILE}
		ERR=$?
		CCREMICHECK="$ERR"
			if [ "$CCREMICHECK" == '0' ]; then
				yumpriorremi
				echo ""
			else
				cecho "Error: problem with ${CENTOSSIXREMIFILE} install." $boldgreen
				exit $ERR
			fi  	
  	else
  	echo "Error: ${CENTOSSIXREMIFILE} not found !!! Downloading now......"
  	wget ${WGETOPT} ${CENTOSSIXREMI} --tries=3
  	# wget ${WGETOPT} ${CENTOSSIXREMILOCAL} --tries=3
	ERROR=$?
		if [[ "$ERROR" != '0' ]]; then
		cecho "Error: ${CENTOSSIXREMIFILE} download failed." $boldgreen
	FAILREMI='y'
	checklogdetails
		# exit #$ERROR
	else 
		cecho "Download done." $boldyellow
		rpm -ivh --nosignature ${CENTOSSIXREMIFILE}
		ERR=$?
		CCREMICHECK="$ERR"
			if [ "$CCREMICHECK" == '0' ]; then
				yumpriorremi
				echo ""
			else
				cecho "Error: problem with ${CENTOSSIXREMIFILE} install." $boldgreen
				exit $ERR
			fi
		fi
	
	fi

# fi # MACHINE_TYPE

fi # REMIREPO_DISABLE

}

###############################################
yumcentossixdownload() {

if [[ "$CENTOSVER" = '6.0' || "$CENTOSVER" = '6.1' || "$CENTOSVER" = '6.2' || "$CENTOSVER" = '6.3' || "$CENTOSVER" = '6.4' || "$CENTOSVER" = '6.5' || "$CENTOSVER" = '6.6' || "$CENTOSVER" = '6.7' || "$CENTOSVER" = '6.8' || "$CENTOSVER" = '6.9' ]]; then
{
echo "*************************************************"
cecho "* CentOS 6.x detected installing EPEL Repo" $boldgreen
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
	if [ -s "${CENTOSSIXEPELFILE}" ]; then
  	echo "${CENTOSSIXEPELFILE} [found]"
  	else
  	echo "Error: ${CENTOSSIXEPELFILE} not found !!! Downloading now......"
  	wget ${WGETOPT} ${CENTOSSIXEPEL} --tries=3
  	# wget ${WGETOPT} ${CENTOSSIXEPELLOCAL} --tries=3
	ERROR=$?
		if [[ "$ERROR" != '0' ]]; then
		cecho "Error: ${CENTOSSIXEPELFILE} download failed." $boldgreen
	FAILEPEL='y'
	checklogdetails
		# exit #$ERROR
	else 
		cecho "Download done." $boldyellow
		rpm --import http://epel.mirror.constant.com/RPM-GPG-KEY-EPEL-6
		rpm -i ${CENTOSSIXEPELFILE}
		#yum${CACHESKIP} -q list ccache 2>&1 >/dev/null
		ERR=$?
		CCEPELCHECK="$ERR"
			if [ "$CCEPELCHECK" == '0' ]; then
				yumpriorepel
				echo ""
			else
				cecho "Error: problem with ${CENTOSSIXEPELFILE} install." $boldgreen
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
	
	if [ -s "${CENTOSSIXRPMFORGEFILE}" ]; then
  	echo "${CENTOSSIXRPMFORGEFILE} [found]"
	rpm --import http://apt.sw.be/RPM-GPG-KEY.dag.txt
	rpm -i ${CENTOSSIXRPMFORGEFILE}
		ERR=$?
		CCRPMFORGECHECK="$ERR"
			if [ "$CCRPMFORGECHECK" == '0' ]; then
				yumpriorrpmforge
				echo ""
			else
				cecho "Error: problem with ${CENTOSSIXRPMFORGEFILE} install." $boldgreen
				#exit $ERR
			fi	 	
  	else
  	echo "Error: ${CENTOSSIXRPMFORGEFILE} not found !!! Downloading now......"
  	wget ${WGETOPT} ${CENTOSSIXRPMFORGE} --tries=3 
	ERROR=$?
		if [[ "$ERROR" != '0' ]]; then
		cecho "Error: ${CENTOSSIXRPMFORGEFILE} download failed." $boldgreen
	FAILRPMFORGE='y'
	checklogdetails
		#exit #$ERROR
	else 
         	cecho "Download done." $boldyellow
	rpm --import http://apt.sw.be/RPM-GPG-KEY.dag.txt
	rpm -i ${CENTOSSIXRPMFORGEFILE}
		yum${CACHESKIP} -q list axel 2>&1 >/dev/null
		ERR=$?
		CCRPMFORGECHECK="$ERR"
			if [ "$CCRPMFORGECHECK" == '0' ]; then
				yumpriorrpmforge
				echo ""
			else
				cecho "Error: problem with ${CENTOSSIXRPMFORGEFILE} install." $boldgreen
				#exit $ERR
			fi
		fi
	
	fi
fi # RPMFORGEREPO_DISABLE = n

if [[ "$CENTALTREPO_DISABLE" = [nN] ]]; then
if [ -s "${CENTOSSIXCENTALTFILE}" ]; then
  echo "${CENTOSSIXCENTALTFILE} [found]"
  else
  echo "Error: ${CENTOSSIXCENTALTFILE} not found !!! Downloading now......"
  wget ${WGETOPT} ${CENTOSSIXCENTALT} --tries=3
  # wget ${WGETOPT} ${CENTOSSIXCENTALTLOCAL} --tries=3
ERROR=$?
	if [[ "$ERROR" != '0' ]]; then
	cecho "Error: ${CENTOSSIXCENTALTFILE} download failed." $boldgreen
FAILCENTALT='y'
checklogdetails
	# exit #$ERROR
else 
         cecho "Download done." $boldyellow
rpm --import http://centos.alt.ru/pub/repository/centos/RPM-GPG-KEY-CentALT
rpm -i ${CENTOSSIXCENTALTFILE}
yumpriorcentalt
echo ""
	fi

fi
fi # CENTALTREPO_DISABLE

	cd $DIR_TMP

if [ -s "${CENTOSSIXPERCONALRELEASEFILE}" ]; then
  echo "${CENTOSSIXPERCONALRELEASEFILE} [found]"
	rpm --import http://www.percona.com/downloads/RPM-GPG-KEY-percona
	rpm -i ${CENTOSSIXPERCONALRELEASEFILE}
	ERR=$?
	CCPERCONACHECK="$ERR"
		if [ "$CCPERCONACHECK" == '0' ]; then
			yumpriorpercona
			echo ""
		else
			cecho "Error: problem with ${CENTOSSIXPERCONALRELEASEFILE} install." $boldgreen
			exit $ERR
		fi	
  else
  echo "Error: ${CENTOSSIXPERCONALRELEASEFILE} not found !!! Downloading now......"
  wget ${WGETOPT} ${CENTOSSIXPERCONALRELEASE} --tries=3 
ERROR=$?
	if [[ "$ERROR" != '0' ]]; then
	cecho "Error: ${CENTOSSIXPERCONALRELEASEFILE} download failed." $boldgreen
FAILPERCONA='y'
checklogdetails
	# exit #$ERROR
else 
         cecho "Download done." $boldyellow
rpm --import http://www.percona.com/downloads/RPM-GPG-KEY-percona
rpm -i ${CENTOSSIXPERCONALRELEASEFILE}
	#yum -q list axel 2>&1 >/dev/null
	ERR=$?
	CCPERCONACHECK="$ERR"
		if [ "$CCPERCONACHECK" == '0' ]; then
			yumpriorpercona
			echo ""
		else
			cecho "Error: problem with ${CENTOSSIXPERCONALRELEASEFILE} install." $boldgreen
			exit $ERR
		fi
	fi

fi

    cd $DIR_TMP

if [ -s "${CENTOSSIXVARNISHFILE}" ]; then
  echo "${CENTOSSIXVARNISHFILE} [found]"
  rpm --nosignature -i ${CENTOSSIXVARNISHFILE}
	ERR=$?
	CCVARNISHCHECK="$ERR"
		if [ "$CCVARNISHCHECK" == '0' ]; then
			yumpriorvarnish
			echo ""
		else
			cecho "Error: problem with ${CENTOSSIXVARNISHFILE} install." $boldgreen
			exit $ERR
		fi  
  else
  echo "Error: ${CENTOSSIXVARNISHFILE} not found !!! Downloading now......"
  wget ${WGETOPT} ${CENTOSSIXVARNISH} --tries=3
  # wget ${WGETOPT} ${CENTOSSIXVARNISHLOCAL} --tries=3
ERROR=$?
	if [[ "$ERROR" != '0' ]]; then
	cecho "Error: ${CENTOSSIXVARNISHFILE} download failed." $boldgreen
FAILVARNISH='y'
checklogdetails
	# exit #$ERROR
else 
         cecho "Download done." $boldyellow

rpm --nosignature -i ${CENTOSSIXVARNISHFILE}
	#yum -q list axel 2>&1 >/dev/null
	ERR=$?
	CCVARNISHCHECK="$ERR"
		if [ "$CCVARNISHCHECK" == '0' ]; then
			yumpriorvarnish
			echo ""
		else
			cecho "Error: problem with ${CENTOSSIXVARNISHFILE} install." $boldgreen
			exit $ERR
		fi
	fi

fi

####
# axivo centos 6.x 64bit only
# axivosixyum
####
remisixyum
atrpmssixyum


# CentOS 6 repo mirrors aren't fully updated so need to specify actual kernel-headers version
PACKAGEEXTRA='clang clang-devel jemalloc jemalloc-devel pngquant optipng jpegoptim pwgen aria2 pigz pbzip2 xz pxz lz4 libJudy axel glances bash-completion mlocate re2c libmcrypt libmcrypt-devel kernel-headers kernel-devel cmake28'

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

} 2>&1 | tee ${CENTMINLOGDIR}/centminmod_${SCRIPT_VERSION}_${DT}_yuminstall_centos6.log
fi

}