open Css;

type a =
  | Add(string)
  | Sort
  | Remove(string);

let rec contain = (arr, e) =>
  switch (arr) {
  | [] => false
  | [x, ...xs] => x == e || contain(xs, e)
  };

let rec concat = (arr1, arr2) =>
  switch (arr1) {
  | [] => arr2
  | [x, ...xs] => [x, ...concat(xs, arr2)]
  };

let rec filter = (arr, f) =>
  switch (arr) {
  | [] => []
  | [x, ...xs] => f(x) ? [x, ...filter(xs, f)] : filter(xs, f)
  };

let rec merge = (arr1, arr2) =>
  switch (arr1, arr2) {
  | ([], _) => arr2
  | (_, []) => arr1
  | ([a1, ...as1], [a2, ...as2]) =>
    a1 < a2 ? [a1, ...merge(as1, arr2)] : [a2, ...merge(arr1, as2)]
  };

let rec seperate = arr =>
  switch (arr) {
  | [] => ([], [])
  | [a] => ([], [a])
  | [a, b, ...c] =>
    switch (seperate(c)) {
    | (l, r) => ([a, ...l], [b, ...r])
    }
  };

let rec ms = arr =>
  switch (seperate(arr)) {
  | (l, []) => l
  | ([], r) => r
  | (l, r) => merge(ms(l), ms(r))
  };

let reducer = state =>
  fun
  | Add(message) => state->concat([message])
  | Sort => ms(state)
  | Remove(message) => state->filter(x => x !== message);

[@react.component]
let make = () => {
  let (_, dispatchModal) = React.useContext(ModalContext.context);
  let (inputVal, setInputVal) = React.useState(_ => "");
  let (orders, setOrders) = React.useReducer(reducer, []);

  <div className={style([])}>
    <h1 className={style([marginTop(`px(30))])}>
      {"TODO List" |> React.string}
    </h1>
    <MyInput inputVal setInputVal />
    <button
      className={style([
        justifyContent(center),
        alignItems(center),
        height(`px(40)),
        transform(translateY(`px(2))),
        fontSize(`px(24)),
        color(white),
        border(`zero, `none, black),
        borderRadius(`px(4)),
        backgroundColor(`rgb((145, 91, 179))),
      ])}
      onClick={_ =>
        orders->contain(inputVal)
          ? dispatchModal(
              OpenModal(
                MessageModal(
                  "This order has already been existed in the list",
                ),
              ),
            )
          : {
            setOrders(Add(inputVal));
            setInputVal(_ => "");
          }
      }>
      <span className={style([fontSize(`px(16))])}>
        {"Add " |> React.string}
      </span>
      {"+" |> React.string}
    </button>
    <button onClick={_ => setOrders(Sort)}> {"sort" |> React.string} </button>
    <OrderList orders close={x => setOrders(Remove(x))} />
  </div>;
};