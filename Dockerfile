FROM debian:12-slim

RUN apt-get update \
    && apt-get upgrade -y \
    && apt-get install -y \
        xorg-dev \
        wget \
        cmake \
        make \
        gcc \
        g++ \
        curl \
        unzip \
        libudev-dev \
        libflac-dev \
        libopenal-dev \
        libvorbis-dev \
        libfuse2 \
        file

COPY build_csfml.sh /build_csfml.sh

RUN chmod a+x /build_csfml.sh
RUN NOSUDO="yes" /build_csfml.sh

RUN mkdir -p /app/
RUN mkdir -p /out
WORKDIR /app

COPY assets /app/assets
COPY include /app/include
COPY lib /app/lib
COPY src /app/src
COPY fbttf.png /app/fbttf.png
COPY Makefile /app/Makefile
COPY my_rpg.desktop /app/my_rpg.desktop
COPY deps /app/deps

ENV APPIMAGE_EXTRACT_AND_RUN 1

RUN make -C /app app

CMD cp ./FlashBackToTheFuture-x86_64.AppImage /out
