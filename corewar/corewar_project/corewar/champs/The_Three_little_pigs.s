.name "The Three little pigs"
.comment  "Once upon a time there was a mama pig who had three little pigs. She loved them very much, but there was not enough food for all of them to eat, so she sent them out into the big world to seek their fortunes."

st  r1, 367
st  r1, 367
st  r1, 367
st  r1, 367
st  r1, 367
st  r1, 367
st  r1, 367
st  r1, 367
st  r1, 367
st  r1, 367
st  r1, 84

sti   r1, %:up_wall, %1
sti   r1, %:down_wall, %1
sti   r1, %:let_forks, %1

ld    %0, r2
pre_fork:
  live %1
  fork  %:down_wall
  fork  %:up_wall
  zjmp  %:let_forks

up_wall:
  live	%1
  st    r2, -15
  st		r2, -24
  st		r2, -33
  st		r2, -42
  st		r2, -51
  st		r2, -60
  st		r2, -69
  st		r2, -78
  st		r2, -87
  st		r2, -96
  st		r2, -105
  st		r2, -114
  st		r2, -123
  st		r2, -132
  st		r2, -141
  st		r2, -150
  st		r2, -159
  st		r2, -168
  st		r2, -177
  st		r2, -186
  st		r2, -195
  st		r2, -204
  st		r2, -213
  st		r2, -222
  st		r2, -231
  st		r2, -240
  st		r2, -249
  st		r2, -258
  st		r2, -267
  st		r2, -276
  st		r2, -285
  st		r2, -294
  st		r2, -303
  st		r2, -312
  st		r2, -321
  st		r2, -330
  st		r2, -339
  st		r2, -348
  st		r2, -357
  st		r2, -366
  st		r2, -375
  st		r2, -384
  st		r2, -393
  st		r2, -402
  st		r2, -411
  st		r2, -420
  st		r2, -429
  st		r2, -438
  st		r2, -447
  st		r2, -456
  zjmp  %:up_wall

  let_forks:
    live %1
    fork  %:steel_live
    zjmp %:let_forks

steel_live:
  live %1
  live %1
  live %1
  live %1
  live %1
  live %1
  live %1
  live %1
  live %1
  live %1
  ld  %0, r2
  zjmp  %:steel_live

  down_wall:
    live	%1
    st		r2, 456
    st		r2, 447
    st		r2, 438
    st		r2, 429
    st		r2, 420
    st		r2, 411
    st		r2, 402
    st		r2, 393
    st		r2, 384
    st		r2, 375
    st		r2, 366
    st		r2, 357
    st		r2, 348
    st		r2, 339
    st		r2, 330
    st		r2, 321
    st		r2, 312
    st		r2, 303
    st		r2, 294
    st		r2, 285
    st		r2, 276
    st		r2, 267
    st		r2, 258
    st		r2, 249
    st		r2, 240
    st		r2, 231
    st		r2, 222
    st		r2, 213
    st		r2, 204
    st		r2, 195
    st		r2, 186
    st		r2, 177
    st		r2, 168
    st		r2, 159
    st		r2, 150
    st		r2, 141
    st		r2, 132
    st		r2, 123
    st		r2, 114
    st		r2, 105
    st		r2, 96
    st		r2, 87
    st		r2, 78
    st		r2, 69
    st		r2, 60
    st		r2, 51
    st		r2, 42
    st		r2, 33
    st    r2, 24
    zjmp	%:down_wall
