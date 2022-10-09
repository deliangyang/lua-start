define print_state4
  printf "tt: %d\n", $arg0.tt
  if $arg0.tt == 0
    printf "nil\n"
  end
  if $arg0.tt == 1
    printf "boolean\n"
  end
  if $arg0.tt == 2
    printf "light_user_data\n"
  end
  if $arg0.tt == 3
    printf "number\n"
  end
  if $arg0.tt == 4
    printf "string\n"
  end
  if $arg0.tt == 5
    printf "table\n"
  end
  if $arg0.tt == 6
    printf "function\n"
  end
  if $arg0.tt == 7
    printf "user_data\n"
  end
  if $arg0.tt == 8
    printf "thread\n"
  end
  if $arg0.tt == 9
    printf "num_tags"
  end
  if $arg0.tt > 9
    printf "not defined\n"
  end
end