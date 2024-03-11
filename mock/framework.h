#pragma once

#define FRAMEWORK_CONFIG "<tars> \n\
  <application> \n\
    <client> \n\
        locator                     = tars.tarsmock.QueryObj@tcp -h 127.0.0.1 -p 17890 \n \
        sync-invoke-timeout         = 5000 \n \
        async-invoke-timeout        = 60000 \n \
        refresh-endpoint-interval   = 5000 \n \
        sendqueuelimit              = 1000000 \n \
        asyncqueuecap               = 1000000 \n \
        asyncthread                 = 3 \n \
        netthread                   = 2 \n \
        mergenetasync               = 0 \n \
        modulename                  = tars.tarsmock \n \
    </client> \n \
    <server> \n \
        start_output = ERROR \n \
        closecout = 0 \n \
        app      = tars \n \
        server   = tarsmock \n \
        basepath = .  \n \
        datapath = . \n \
        logpath  = . \n \
        netthread = 1 \n \
        mergenetimp = 0 \n \
        opencoroutine = 0 \n \
        loglevel=TARS \n \
        <RegistryAdapter> \n \
            endpoint = tcp -h 127.0.0.1 -p 13004 -t 60000 \n \
            allow	 = \n \
            maxconns = 4096 \n \
            threads	 = 5 \n \
            servant = tars.tarsmock.QueryObj \n \
            queuecap = 1000000 \n \
        </RegistryAdapter> \n \
    </server> \n \
  </application> \n\
</tars>"
